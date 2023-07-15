def main():
    fraction = input('Fraction: ')
    percentage = convert(fraction)
    print(f'{gauge(percentage)}')

def convert(fraction):
    x, y = fraction.split('/')
    if (int(x) / int(y)) > 1:
        raise ValueError
    elif int(y) == 0:
        raise ZeroDivisionError
    return int(int(x) / int(y) * 100)



def gauge(percentage):
    if 0 <= percentage <= 1:
        return 'E'
    elif 99 <= percentage <= 100:
        return 'F'
    elif 1 < percentage < 99:
        return str(round(percentage)) + '%'


if __name__ == "__main__":
    main()