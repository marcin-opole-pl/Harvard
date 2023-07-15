def main():

    # Get card number
    card = input('Card number please: ')
    # Calculate card lenght
    cardlen = len(card)
    # Convert card to int
    cardint = int(card)
    # Evensum initialization
    evensum = 0
    oddsum = 0
    # Lunh's argorithm
    while cardint > 0:
        # Add odd num
        oddsum += cardint % 10
        # Remove last digit
        cardint = cardint // 10
        # Create even num
        evennum = cardint % 10
        # Remove last digit
        cardint = cardint // 10
        # Double even digit
        evendouble = evennum * 2
        # Add even doubles digits
        if evendouble < 10:
            evensum += evendouble
        else:
            # Last digit of evendouble
            i = evendouble % 10
            # Remove last digit of evendouble
            evendouble = evendouble // 10
            j = evendouble % 10
            # Even doubles sum
            evensum = evensum + i + j
    # Lunh value
    lunh = int(oddsum + evensum)
    modlunh = lunh % 10
    # Card check algorithm
    if modlunh == 0 and cardlen == 15 and card[0] == '3' and card[1] == '4':
        print('AMEX')
    elif modlunh == 0 and cardlen == 15 and card[0] == '3' and card[1] == '7':
        print('AMEX')
    elif cardlen == 16 and card[0] == '5' and modlunh == 0 and card[1] == '1':
        print('MASTERCARD')
    elif cardlen == 16 and card[0] == '5' and modlunh == 0 and card[1] == '2':
        print('MASTERCARD')
    elif cardlen == 16 and card[0] == '5' and modlunh == 0 and card[1] == '3':
        print('MASTERCARD')
    elif cardlen == 16 and card[0] == '5' and modlunh == 0 and card[1] == '4':
        print('MASTERCARD')
    elif cardlen == 16 and card[0] == '5' and modlunh == 0 and card[1] == '5':
        print('MASTERCARD')
    elif cardlen == 13 and card[0] == '4' and modlunh == 0:
        print('VISA')
    elif cardlen == 16 and card[0] == '4' and modlunh == 0:
        print('VISA')
    else:
        print('INVALID')


if __name__ == "__main__":
    main()