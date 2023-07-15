import re
import sys
from um import count

def test_count_1():
    assert count('um. Umbrela UM. gum.') == 2

def test_count_2():
    assert count('dog.um') == 1

def test_count_3():
    assert count('UM?') == 1