def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    # Check for only letters plates
    if 2 <= len(s) <= 6:
        if s.isalpha():
            return True
    # Check for no punctuation marks
    if 2 <= len(s) <= 6:
        if s.isalnum():
            # Check if first two chars are letters
            i = s[0:2]
            if i.isalpha():
                # Check for zero 0 and no letters after digits
                for j in range(2, len(s)-1):
                    if s[j:].isdecimal():
                        # Check for 0 at begining
                        if not s[j:].startswith('0'):
                            # Check if alpha after digit
                            for k in range(3, len(s)):
                                if not s[k:].isalpha():
                                    return True
    else:
        return False


main()