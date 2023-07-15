text = input('Input: ')
vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

for char in text:
    if char in vowels:
        print('', end='')
    else:
        print(char, end='')