import random

try:
    # Get level
    level = int(input('Level: '))
    # Check if level is positive int
    if level < 1:
        level = int(input('Level: '))
    else:
        while True:
            try:
                # Get guess
                guess = int(input('Guess: '))
                # Check if guess is positive int
                if guess < 1:
                    guess = int(input('Guess: '))
                else:
                    # Create a random int in range 1 - level (inclusivly)
                    random_int = random.randint(1, int(level))
                    # Too small
                    if int(guess) < random_int:
                        print('Too small!')
                    # Too large
                    elif int(guess) > random_int:
                        print('Too large!')
                    # Just right = exit
                    else:
                        print('Just right!')
                        break
            except ValueError:
                guess = int(input('Guess: '))
except ValueError:
    level = int(input('Level: '))
