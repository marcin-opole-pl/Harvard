#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void calc_binars(bool table, int y);

int main(void)
{
    // Get message
    string message = (get_string("Message: "));
    // Convert message into ints
    int j = strlen(message);
    int dec_letter[j];
    for (int i = 0; i < strlen(message); i++)
    {
        dec_letter[i] = message[i];
    }
    // Creation of boolean table - all values set 0
    bool table[j][BITS_IN_BYTE];
    for (int line = 0; line < j; line++)
    {
        for (int col = 0; col < BITS_IN_BYTE; col++)
            table[line][col] = 0;
    }
    // Convert decimal ints into binar ints
    for (int line = 0; line < j; line++)
    {

    }
}
void calc_binars(bool table, int y)
{
    int line;
    int dec_letter[line];
    int x = dec_letter[line];
    bool table[line][int];
        if (x % 2 == 1)
        {
            table[line][7] = 1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][6] = 1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][5] = 1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][4] =1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][3] = 1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][2] = 1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][1] =1;
        }
        x = x / 2;
        if (x % 2 == 1)
        {
            table[line][0] =1;
        }
}



void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
