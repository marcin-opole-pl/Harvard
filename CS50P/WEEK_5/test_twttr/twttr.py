def main():
    text = input('Input: ')
    print(f'{shorten(text)}')


def shorten(word):
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    twttr = ''
    for char in word:
        if char not in vowels:
            twttr += char
    word = twttr
    return word


if __name__ == "__main__":
    main()