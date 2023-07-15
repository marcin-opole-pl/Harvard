# Function to convert to emoji
def convert(str):
    output = str.replace(':)', '🙂').replace(':(', '🙁')
    return output

def main():
    text = input('Input text: ')
    output = convert(text)
    print(output)

main()