from plates import is_valid

# “All vanity plates must start with at least two letters.”
def test_1():
    assert is_valid('C') == False
    assert is_valid('50') == False
    assert is_valid('CS') == True
    assert is_valid('CSTWRW') == True

# “… vanity plates may contain a maximum of 6 characters
# (letters or numbers) and a minimum of 2 characters.”
def test_2():
    assert is_valid('CSG50') == True
    assert is_valid('CASCDTE') == False


# “Numbers cannot be used in the middle of a plate;
# they must come at the end. For example, AAA222 would be an acceptable
#  … vanity plate; AAA22A would not be acceptable.
# The first number used cannot be a ‘0’.”
def test_3():
    assert is_valid('CSG025') == False
    assert is_valid('CSG25A') == False
    assert is_valid('CSG125') == True
# “No periods, spaces, or punctuation marks are allowed.”
def test_4():
    assert is_valid('CAS!') == False