import sys
import pytest
from datetime import date
from seasons import get_birth, convert


def test_input():
    with pytest.raises(SystemExit):
        get_birth('dog')

def test_convert():
    convert(date(1970, 1, 30)) == 'Twenty-eight million, thirty-eight thousand, two hundred forty minutes'
