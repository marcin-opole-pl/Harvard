i = input('Expression: ')
x, y, z, = i.split(' ')
x = int(x)
z = int(z)
if y == '+':
    k = (float(x + z))
    print('%.1f' % k)
elif y == '-':
    k = (float(x - z))
    print('%.1f' % k)
elif y == '*':
    k = (float(x * z))
    print('%.1f' % k)
elif y == '/':
    k = (float(x / z))
    print('%.1f' % k)