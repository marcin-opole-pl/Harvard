from cs50 import get_int


def main():
    h = 0
    # Check for range
    while h < 1 or h > 8:
        h = get_int('Height please: ')
    # Print pyramid
    for i in range(1, h + 1):
        # Print '_'
        for j in range(h - i, 0, -1):
            print(' ', end='')
        # Print '#'
        for j in range(0, i):
            print('#', end='')
        # Print '__'
        print('  ', end='')
        # Print '#'
        for j in range(0, i):
            print('#', end='')
        # Print enter
        print('')


if __name__ == "__main__":
    main()