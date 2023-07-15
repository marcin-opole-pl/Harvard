from fuel import convert, gauge
import pytest

def test_convert():
    assert convert('3/4') == 75
    assert convert('4/4') == 100

def test_gauge():
    assert gauge(1) == 'E'
    assert gauge(99) == 'F'
    assert gauge(75) == '75%'

def test_ZeroDivisionError():
    with pytest.raises(ZeroDivisionError):
        convert('2/0')

def test_ValueError():
    with pytest.raises(ValueError):
        convert('4/3')