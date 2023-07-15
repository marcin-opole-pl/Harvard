from jar import Jar
import pytest


def test_init():
    ...


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit_1():
    jar = Jar()
    with pytest.raises(NameError):
        jar.deposit(dog)


def test_deposit_2():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.deposit(15)


def test_withdraw():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.withdraw(15)