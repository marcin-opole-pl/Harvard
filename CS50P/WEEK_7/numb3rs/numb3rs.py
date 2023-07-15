import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    no = '^(([0-1]?[0-9]?[0-9]?|2[0-4]?[0-9]?|25[0-5]?)\.){3}([0-1]?[0-9]?[0-9]?|2[0-4]?[0-9]?|25[0-5]?)$'
    address = re.search(no, ip)
    if address:
        return True
    else:
        return False

if __name__ == "__main__":
    main()