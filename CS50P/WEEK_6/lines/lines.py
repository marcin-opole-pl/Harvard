import sys


def main():
    file_name = sys.argv
    print(lines_calc(get_argv(file_name)))


# Check if correct no of inline-commands
def get_argv(name):
    #name = name.split(' ')
    if len(name) < 2:
        sys.exit('Too few command-line arguments')
    elif len(name) > 2:
        sys.exit('Too many command-line arguments')
    elif len(name) == 2:
        command = name[1]
        _, y = command.split('.')
        if y != 'py':
            sys.exit('Not a Python file')
        else:
            return command


# Calculate no of lines in file
def lines_calc(name):
    # Check if file exist
    try:
        f = open(name)
    except FileNotFoundError:
        sys.exit('File does not exist')
    else:
        no_lines = 0
        for line in f:
            # Exclude comments nad whitespace
            if not (line.lstrip().startswith('#') or line.strip() == ''):
                no_lines += 1
        f.close()
        return no_lines

    
if __name__ == '__main__':
    main()