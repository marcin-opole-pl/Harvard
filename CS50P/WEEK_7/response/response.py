import validators


def main():
    print(valid(input('What"s your email address? ')))


def valid(s):
    if validators.email(s) == True:
        return 'Valid'
    else:
        return 'Invalid'

if __name__ == '__main__':
    main()