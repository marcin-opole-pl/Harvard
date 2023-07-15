#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if only one commandline agrument
    if (argc != 2)
    {
        printf("One argument needed \n");
        return 1;
    }
    // Check if argument has 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("26 letters required \n");
        return 1;
    }
    // Check if any chars are nonalphabetic
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Only letters accepted \n");
            return 1;
        }
    }
    // Check if no two similars letters
    for (int i = 0; i < (strlen(argv[1]) - 1); i++)
    {
        if (tolower(argv[1][i]) == tolower(argv[1][i+1]))
        {
            printf("No similar letters \n");
            return 1;
        }
    }
    char key[strlen(argv[1])];
    //AGRV tolower
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        key[i] = tolower(argv[1][i]);
    }
    // Get plaintext
    string plaintext = get_string("plaintext:");
    // Print ciphertext
    printf("ciphertext:");
    // Get ciphertext
    // Loop all chars in plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    // Replace lowercase with key
    {
        if (islower(plaintext[i]))
        {
            for (int j = 0; j < strlen(key); j++)
            {
                    if(plaintext[i] == (j + 97))
                    {
                    int c = tolower(key[j]);
                    printf("%c", c);
                    }
            }
        }
        else if (isupper(plaintext[i]))
        {
            for (int j = 0; j < strlen(key); j++)
                {
                    if(plaintext[i] == (j + 65))
                    {
                        int c = toupper(key[j]);
                        printf("%c", c);
                    }
                }
        }
        else
                {
                    char c = plaintext[i];
                    printf("%c", c);
                }

    }

    printf("\n");
}