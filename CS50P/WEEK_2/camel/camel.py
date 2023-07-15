camel = input('camelCase:')

print('snake_case: ', end='')
for char in camel:
    if char.islower():
        print(char, end='', sep='')
    elif char.isupper():
        print('_', char.lower(), end='', sep='')