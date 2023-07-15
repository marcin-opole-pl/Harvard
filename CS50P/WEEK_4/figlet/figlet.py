from pyfiglet import Figlet

figlet = Figlet()

import sys
import random

argv1 = ['-f', '--font']

# If argv=0 randomize font
if len(sys.argv) == 1:
    s = input('Input: ')
    f = random.choice(figlet.getFonts())
    figlet.setFont(font=f)
    print('Output: ', figlet.renderText(s))
# Check argv 1 and 2 correctness
elif len(sys.argv) == 3 and sys.argv[1] in argv1 and sys.argv[2] in figlet.getFonts():
    s = input('Input: ')
    figlet.setFont(font=sys.argv[2])
    print('Output: ', figlet.renderText(s))
# sys.exit
else:
    sys.exit('Invalid usage')