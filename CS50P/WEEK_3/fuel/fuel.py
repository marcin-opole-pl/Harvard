def main():
    z = get_fraction()

    if 0 <= z <= 0.01:
        print('E')
    elif 0.99 <= z <= 1:
        print('F')
    elif 0.01 < z < 0.99:
        print(str(round(z * 100)) + '%')


def get_fraction():
    while True:
        try:
            x, y = input('Fraction: ').split('/')
            if (int(x) / int(y)) <= 1:
                return (int(x) / int(y))
        except (ValueError, ZeroDivisionError):
            pass


main()