import random


def main():
    level = get_level()
    score = 0


    for _ in range(10):
        errors = 0
        x = generate_integer(level)
        y = generate_integer(level)
        z = x + y
        # Ask user for result
        while errors < 3:
            try:
                result = int(input(f'{x} + {y} = '))
                # If result correct
                if z == result:
                    score += 1
                    break
                # If result incorrect
                while z != result:
                        print('EEE')
                        errors += 1
                        break
            # If result is not an int
            except ValueError:
                print('EEE')
                errors += 1
                raise ValueError
                pass
        # Errors limit reached
        if errors == 3:
            print(f'{x} + {y} = {z} ')

    print(f'Score: {score}')


def get_level():
    # Get level from user
    level = input('Level: ')
    # Check if level is int
    if level.isalpha():
        level = input('Level: ')
    # Check is level is 1,2,3
    if int(level) not in [1, 2, 3]:
        level = input('Level: ')
    else:
        x = int(level)
        return x


def generate_integer(level):
    try:
        if level == 1:
            return random.randint(0, 9)
        elif level == 2:
            return random.randint(10, 99)
        elif level == 3:
            return random.randint(100, 999)
    except:
        raise ValueError



if __name__ == "__main__":
    main()