#include <cs50.h>
#include <stdio.h>

// Building piramyd accordingly to input

int main(void)

{

// Get input
int height;
    do
    {
        height = get_int("Input height: ");
    }
    while (height > 8 || height < 1);

// Input 1 print piramyd
    if (height == 1)
    {
        printf("#  #\n");
    }
// Input 2 print piramyd
    if (height == 2)
    {
        printf(" #  #\n##  ##\n");
    }
// Input 3 print piramyd
    if (height == 3)
    {
        printf("  #  #\n ##  ##\n###  ###\n");
    }
// Input 4 print piramyd
    if (height == 4)
    {
        printf("   #  #\n  ##  ##\n ###  ###\n####  ####\n");
    }
// Input 5 print piramyd
    if (height == 5)
    {
        printf("    #  #\n   ##  ##\n  ###  ###\n ####  ####\n#####  #####\n");
    }
// Input 6 print piramyd
    if (height == 6)
    {
        printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n######  ######\n");
    }
// Input 7 print piramyd
    if (height == 7)
    {
        printf("      #  #\n     ##  ##\n    ###  ###\n   ####  ####\n  #####  #####\n ######  ######\n#######  #######\n");
    }
// Input 8 print piramyd
    if (height == 8)
    {
        printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
    }
}