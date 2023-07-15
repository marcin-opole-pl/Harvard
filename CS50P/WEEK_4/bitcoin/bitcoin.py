import sys
import requests
import json


def main():
    if len(sys.argv) == 1:
        sys.exit('Missing command-line argument')
    elif sys.argv[1].isalpha():
        sys.exit("Command-line argument is not a number")
    else:
        n = float(sys.argv[1])
        print(bit(n))


def bit(n):
    try:
        feedback = requests.get('https://api.coindesk.com/v1/bpi/currentprice.json')
        data = feedback.json()
        price = data['bpi']['USD']['rate_float']
        return f'${(price * n):,.4f}'
    except requests.RequestException:
        return None


main()
