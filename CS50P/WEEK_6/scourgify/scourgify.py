import sys
import csv
from tabulate import tabulate

def main():
    command = sys.argv
    readf, writef = argv_check(command)
    students = []

    # Read csv
    with open (readf) as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row['name'].split(', ')
            first = name[1]
            last = name[0]
            house = row['house']
            students.append({'first': first, 'last': last, 'house': house})
    # TEMP
    #print(tabulate(students, tablefmt='grid'))

    # Write after.cvs
    with open(writef, 'w') as file:
        writer = csv.DictWriter(file, fieldnames=['first', 'last', 'house'])
        writer.writeheader()
        writer.writerows(students)


# Check correctness of argv
def argv_check(command):
    if len(command) < 3:
        sys.exit('Too few command-line arguments')
    elif len(command) > 3:
        sys.exit('Too many command-line arguments')
    else:
        try:
            f = open(command[1])
        except FileNotFoundError:
            sys.exit(f'Could not read {command[1]}')
        else:
            readf = command[1] 
            writef = command[2]
            return readf, writef


if __name__ == '__main__':
    main()