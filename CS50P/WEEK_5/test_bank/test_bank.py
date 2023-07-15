from bank import value

def test_value_hello():
    assert value('hello') == 0

def test_value_HELLO():
    assert value('HELLO') == 0

def test_value_home():
    assert value('home') == 20

def test_value_h():
    assert value('h') == 20

def test_value_space():
    assert value(' ') == 100

def test_value_1():
    assert value('1') == 100