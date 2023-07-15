amount = 50
paid = 0
accepted = [5, 10, 25]

# Ask for coins
while amount > 0:
    print(f'Amount Due: {amount}')
    insert = int(input('Insert Coin: '))
        # Check if coin is accepted
    if insert in accepted:
        # Update amount
        paid += insert
        amount -= insert

# Print change
if paid >= amount:
    print(f'Change Owed: {paid - 50}')


