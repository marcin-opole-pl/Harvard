from datetime import date, timedelta
import sys
import operator
import inflect

p = inflect.engine()


def main():
    # Get date of birth
    x = input('Date of Birth: ')
    # Do the rest
    convert(get_birth(x))


def convert(birth):
    # Get current time
    time = date.today()
    # Calculate the difference
    diff = operator.sub(time, birth)
    # Convert days into minutes
    minutes = diff.days * 60 * 24
    # Convert numerals into words
    print(f'{(p.number_to_words(minutes, andword="")).capitalize()} minutes')


def get_birth(x):
    # Convert date of birth
    try:
        y, m, d = x.split('-')
    except:
        sys.exit('Invalid date')
    try:
        birth = date(int(y), int(m), int(d))
    except:
        sys.exit('Invalid date')
    else:
        return birth

if __name__ == "__main__":
    main()