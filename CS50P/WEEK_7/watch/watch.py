import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    match = re.search(r'<iframe.*(youtube).*embed/(\w+)".*></iframe>', s)
    if match:
        yt = match.group(2)
        return f'https://youtu.be/{yt}'
    else:
        return None


if __name__ == "__main__":
    main()