import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session['user_id']
    # Get transactions info form db
    rows = db.execute('SELECT * FROM assets WHERE user_id = ?', user_id)

    # Get cash info from users.db
    cash_db = db.execute('SELECT cash FROM users WHERE user_id = ?', user_id)
    cash = cash_db[0]['cash']

    # Total value of cash and shares
    total = float(cash)

    # Add shares values
    for row in rows:
        quote = lookup(row['symbol'])
        row['name'] = quote['name']
        row['price'] = quote['price']
        row['value'] = row['price'] * row['shares']
        total += row['value']
        row['value'] = usd(row['value'])
        row['price'] = usd(row['price'])

    return render_template('index.html', rows=rows, cash=usd(cash), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get('symbol')
        shares = request.form.get('shares')
        quote = lookup(symbol)
        shares = int(shares)

        # Check if stock symbol provided
        if not symbol:
            return apology('must provide stock symbol', 400)

        # Check if symbol exists in IEX database
        if quote == None:
            return apology("symbol does not exist", 400)

        # Check if shares >= 1
        if shares < 1:
            return apology("Can not buy this amount", 400)

        # Check if shares are float
        if shares%1 != 0:
            return apology("Can not buy this amount", 400)

        # Check if enough money
        cost = shares * quote['price']
        user_id = session['user_id']
        cash_db = db.execute('SELECT cash FROM users WHERE user_id = ?', user_id)
        cash = cash_db[0]['cash']
        if cash < cost:
            return apology("Not enough money", 400)

        # Update users.db
        cur_cash = cash - cost
        db.execute('UPDATE users SET cash = ? WHERE user_id = ?', cur_cash, user_id)

        # Update assets.db
        row = db.execute('SELECT * FROM assets WHERE symbol = ? AND user_id = ?', symbol, user_id)

        # If entry does not exist create a row
        if len(row) != 1:
            db.execute('INSERT INTO assets (user_id, symbol) VALUES (?, ?)', user_id, symbol)

        # Get current shares no
        curr_shares = db.execute('SELECT shares FROM assets WHERE user_id = ? AND symbol = ?', user_id, symbol)
        curr_shares = curr_shares[0]['shares']

        # Add purchased shares to current no
        shares_value = curr_shares + shares

        # Update shares no in db
        db.execute('UPDATE assets SET shares = ? WHERE user_id = ? AND symbol = ?', shares_value, user_id, symbol)

        # Update history.db
        date = datetime.datetime.now()
        db.execute('INSERT INTO history (user_id, symbol, shares, price, date, method) VALUES (?, ?, ?, ?, ?, ?)',
                    user_id, quote['symbol'], shares, quote['price'], date, 'Buy')

        flash('Bought')

        return redirect("/")

    # Route accesssed via GET
    else:
        return render_template('buy.html')


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute('SELECT * FROM history WHERE user_id = ?', session['user_id'])

    return render_template('history.html', rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["user_id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol was submitted
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)

        # Check if symbol exists in IEX database
        if lookup(symbol) == None:
            return apology("symbol does not exist", 400)

        # Return template with stock quote
        x = lookup(symbol)
        return render_template('quoted.html', name=x['name'], symbol=x['symbol'], price=usd(x['price']))

    # Route accesssed via GET
    else:
        return render_template('quote.html')


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure passwords match
        elif request.form.get('password') != request.form.get('confirmation'):
            return apology("passwords don't match", 400)

        # Store username and hashed password
        user = request.form.get('username')
        hash = generate_password_hash(request.form.get('password'))

        # Save data to db and check if user already exists
        try:
            db.execute('INSERT INTO users(username, hash) VALUES(?, ?)', user, hash)
        except:
            return apology('username already taken', 400)

        # Redirect to login page
        return redirect('/')

    # Route accessed via GET
    else:
        return render_template('register.html')


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    user_id = session['user_id']

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        symbol = request.form.get('symbol')
        shares = int(request.form.get('shares'))
        quote = lookup(symbol)

        # Check if stock symbol provided
        if not symbol:
            return apology('must provide stock symbol', 400)

        # Check if symbol exists in IEX database
        if quote == None:
            return apology("symbol does not exist", 400)

        # Check if shares > 0
        if shares < 0:
            return apology("Can not sell this amount", 400)

        # Check if shares are owned
        rows = db.execute('SELECT * FROM assets WHERE user_id = ? AND symbol = ?', user_id, symbol)
        if len(rows) != 1:
            return apology("You don't own this stock", 400)

        # Current no of shares
        curr_shares = rows[0]['shares']

        # Check if owned enough shares
        if shares > curr_shares:
            return apology("You don't own enough shares", 400)

        # Calculate the value of sale
        sale = shares * quote['price']

        # Update cashflow
        cash_db = db.execute('SELECT cash FROM users WHERE user_id = ?', user_id)
        cash = cash_db[0]['cash']
        cash += sale
        db.execute('UPDATE users SET cash = ? WHERE user_id = ?', cash, user_id)

        # Update shares no in assets.db
        owned_shares = curr_shares - shares
        # If shares remain after sale
        if owned_shares > 0:
            db.execute('UPDATE assets SET shares = ? WHERE user_id = ? AND symbol = ?', owned_shares, user_id, symbol)
        # All shares sold
        else:
            db.execute('DELETE FROM assets WHERE user_id = ? AND symbol = ?', user_id, symbol)

        # Update history.db
        date = datetime.datetime.now()
        db.execute('INSERT INTO history (user_id, symbol, shares, price, date, method) VALUES (?, ?, ?, ?, ?, ?)',
                    user_id, quote['symbol'], shares, quote['price'], date, 'Sell')

        flash('Sold')

        return redirect("/")

    # Route accessed via GET
    else:
        # Get current assets
        assets = db.execute('SELECT * FROM assets WHERE user_id = ?', user_id)
        return render_template('sell.html', assets=assets)


@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    """Adds cash to account"""

    user_id = session['user_id']

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        cash = request.form.get('cash')
        cash = int(cash)
        if cash < 0:
            return apology("You can not witdraw money", 403)
        else:
            old_amount_db = db.execute('SELECT cash FROM users WHERE user_id = ?', user_id)
            old_amount = old_amount_db[0]['cash']
            new_amount = old_amount + cash
            # Add money to the account
            db.execute('UPDATE users SET cash = ? WHERE user_id = ?', new_amount, user_id)

        flash('Money added')

        return redirect("/")

    # Route accessed via GET
    else:
        return render_template('add.html')