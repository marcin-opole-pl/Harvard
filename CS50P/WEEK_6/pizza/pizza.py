import sys
from tabulate import tabulate
import csv

def main():
    command = sys.argv
    menu = csv_read(argv_check(command))
    with open(menu) as file:
        reader = csv.reader(file)
        print(tabulate(reader, headers='firstrow', tablefmt='grid'))


# Check if correct command-line arg
def argv_check(command):
    if len(command) < 2:
        sys.exit('Too few command-line arguments')
    elif len(command) > 2:
        sys.exit('Too many command-line arguments')
    elif len(command) == 2:
        try:
            _, x = command[1].split('.')
        except:
            sys.exit('Not a CSV file')
        else:
            if x != 'csv':
                sys.exit('Not a CSV file')
            else:
                return command[1]


# Read csv file
def csv_read(file):
    try:
        f = open(file)
    except FileNotFoundError:
        sys.exit('File does not exist')
    else:
        f.close
        return file

if __name__ == '__main__':
    main()