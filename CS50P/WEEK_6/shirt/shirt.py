import sys
from PIL import Image, ImageOps

ext = ('jpg', 'jpeg', 'png')


def main():
    command = sys.argv
    before, after = check_argv(command)

    # Open muppet and check if file exists
    try:
        before = Image.open(before)
    except FileNotFoundError:
        sys.exit('Input does not exist')
    else:
        # Open shirt
        shirt = Image.open('shirt.png')
        size = shirt.size

        # Resize muppet
        model = ImageOps.fit(before, size)

        # Paste shirt on muppet
        model.paste(shirt, mask=shirt)

        # Print after
        #model.show()

        # Save image
        model.save(after)

        # Close opened files
        before.close()
        shirt.close()


def check_argv(command):
    if len(sys.argv) < 3:
        sys.exit('Too few command-line arguments')
    elif len(sys.argv) > 3:
        sys.exit('Too many command-line arguments')
    try:
        _, ext1 = command[1].split('.')
    except:
        sys.exit('Invalid input')
    try:
        _, ext2 = command[2].split('.')
    except:
        sys.exit('Invalid output')
    else:
        if ext2.lower() not in ext:
            sys.exit('Invalid input')
        elif ext1.lower() != ext2.lower():
            sys.exit('Input and output have different extensions')
        else:
             return command[1], command[2]


if __name__ == "__main__":
    main()