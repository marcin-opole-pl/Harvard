import inflect

sep = inflect.engine()
names = []

while True:
    try:
        name = input('Name: ').strip().title()
        names.append(name)
    except EOFError:
        print('Adieu, adieu, to', sep.join(names))
        break
    