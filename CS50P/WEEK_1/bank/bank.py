answer = input('Greeting: ')
output = answer.lower().strip()
if output.startswith('hello'):
    print('$0')
elif output.startswith('h'):
    print('$20')
else:
    print('$100')