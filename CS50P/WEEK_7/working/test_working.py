import re
import sys
import pytest
from working import convert

def test_ValErr():
    with pytest.raises(ValueError):
        convert('13:00 AM to 11:65 PM')

def test_dog():
    with pytest.raises(ValueError):
        convert('dog')

def test_convert_1():
    assert convert('9:00 AM to 12:00 AM') == '09:00 to 00:00'

def test_convert_2():
    assert convert('9:00 PM to 12:00 PM') == '21:00 to 12:00'