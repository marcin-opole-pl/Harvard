from cs50 import get_string
from curses.ascii import isalpha


def main():

    text = get_string('Text: ')
    letters_no = int(0)
    # Count letter
    for i in range(len(text)):
        if isalpha(text[i]):
            letters_no += 1
    # Count blanks
    blank_no = int(0)
    for i in range(len(text)):
        if text[i] == ' ':
            blank_no += 1
    # Count words
    word_no = blank_no + 1
    # Count . ! ?
    sentence_no = int(0)
    for i in range(len(text)):
        if text[i] == '.':
            sentence_no += 1
        if text[i] == '!':
            sentence_no += 1
        if text[i] == '?':
            sentence_no += 1
    # Compute Coleman-Liau index
    L = letters_no / word_no * 100
    S = sentence_no / word_no * 100
    index = (0.0588 * L) - (0.296 * S) - 15.8
    score = round(index)
    # Print results
    if (score < 1):
        print('Before Grade 1')
    elif (score >= 16):
        print('Grade 16+')
    else:
        for i in range(2, 16):
            if score == i:
                print('Grade ', i)


if __name__ == "__main__":
    main()