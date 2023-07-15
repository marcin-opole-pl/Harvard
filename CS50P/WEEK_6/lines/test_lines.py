from lines import get_argv, lines_calc
import pytest
import sys

# Only 1 argv 
def test_arv_1():
    with pytest.raises(SystemExit) as e:
        get_argv('lines.py')
    assert e.type == SystemExit
    assert e.value.code == 'Too few command-line arguments'

# More then 1 argv command
def test_argv_2():
    with pytest.raises(SystemExit) as e:
        get_argv('lines.py hello.py goodbye.py') 
    assert e.type == SystemExit
    assert e.value.code == 'Too many command-line arguments'

# File is not .py
def test_argv_3():
    with pytest.raises(SystemExit) as e:
        get_argv('lines.py hello.txt') 
    assert e.type == SystemExit
    assert e.value.code == 'Not a Python file'

# File does not exist
def lines_calc_1():
    with pytest.raises(SystemExit) as e:
        lines_calc('lines.py hello.txt') 
    assert e.type == SystemExit
    assert e.value.code == 'File does not exist'