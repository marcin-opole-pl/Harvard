answer = input('What is an answer to the Great Question of Life, the Universe and Everything?')
output = answer.lower().strip()
if output == '42' or output == 'forty-two' or output == 'forty two':
    print('Yes')
else:
    print("No")