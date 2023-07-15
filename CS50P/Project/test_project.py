import pytest
from project import new_hour, new_minute, new_second, check_func

def test_new_hour():
    STATE = 0
    assert new_hour() == 0


def test_new_minute():
    STATE = 0
    assert new_minute() == 0


def test_new_second():
    STATE = 0
    assert new_second() == 0

