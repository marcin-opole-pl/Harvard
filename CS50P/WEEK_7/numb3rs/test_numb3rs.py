import re
import sys
from numb3rs import validate

def test_validate_1():
    assert validate('dog') == False

def test_validate_2():
    assert validate('1') == False

def test_validate_3():
    assert validate('245.285.1.1') == False

def test_validate_4():
    assert validate('245.245.245.245') == True
