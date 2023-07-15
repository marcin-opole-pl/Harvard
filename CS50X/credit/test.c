#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Get card numer
    long cardnumber;
    cardnumber = get_long("Card number please: \n");

// Calculate card lenght
    int ii;
    ii = 0;
    long cardlenght;
    cardlenght = cardnumber;
    while (cardlenght > 0)
    {
        cardlenght = cardlenght / 10;
        ii++;
    }


    // Check if lenght valid
    if (ii != 13 && ii != 15 && ii != 16)
    {
        printf("INVALID\n");
    }

// Lunh's algorithm
    long card;
    card = cardnumber;
    int sumeven = 0;
    int sumodd = 0;
    int modeven = 0;
    int mododd = 0;
    int evenno = 0;
    int evendouble = 0;

    do
    {

// Remove odd char and add value
        sumodd = sumodd + card % 10;
        card = card / 10;

// Remove even char and add value
        evenno = card % 10;
        card = card / 10;
        evendouble = evenno *2;
        if (evendouble < 10)
        {
            sumeven = sumeven + evendouble;
        }
        else
        {
            int j = 0;
            int k = 0;
            j = evendouble % 10;
            evendouble = evendouble / 10;
            k = evendouble % 10;
            sumeven = sumeven + j + k;
        }
    }
    while (card > 0);

// Lunh's value
    int lunh;
    lunh = sumodd + sumeven;
    if ( lunh % 10 != 0)
    {
        printf("INVALID\n");
    }

// Check card type

        i = 0;
        long cardprov = cardnumber;
        while (i < 12)
        {
// Check char 13
             cardprov = cardprov / 10;
             i++;
        }
        int j13 = 0;
        j13 = cardprov % 10;
// Check char 14
        int j14 = 0;
        cardprov = cardprov / 10;
        j14 = cardprov % 10;
// Check char 15
        int j15 = 0;
        cardprov = cardprov /10;
        j15 = cardprov % 10;
// Check char 16
        int j16 = 0;
        cardprov = cardprov /10;
        j16 = cardprov % 10;

        if (j13 == 4 || j16 == 4)
            printf("VISA\n");
        else if ((j14 == 4 || j14 == 7) && j15 == 3)
            printf("AMEX\n");
        else if ((j15 == 1 || j15 == 2 || j15 == 3 || j15 == 4 || j15 == 5) && j16 == 5)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");


}