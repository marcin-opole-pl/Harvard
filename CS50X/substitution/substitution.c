#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


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
    // Get plaintext
    string plaintext = get_string("plaintext:  ");
    // Print ciphertext
    printf("ciphertext: ");
    // Get ciphertext
    char ciphertext[strlen(plaintext)];
    // Loop to check all letters in plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Check if plaintext is nonalphabetic
        if (!isalpha(plaintext[i]))
        // Output unchanged plaintext
        {
            ciphertext[i] = plaintext[i];
        }
        if (isalpha(plaintext[i]))
        {
            char low_LETTER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',};
            char up_LETTER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',};
            // Loop to check all chars in key
            for (int k = 0; k < strlen(argv[1]); k++)
                {
                    if (plaintext[i] == low_LETTER[k])
                    {
                       ciphertext[i] = tolower(argv[1][k]);
                    }
                    if (plaintext[i] == up_LETTER[k])
                    {
                       ciphertext[i] = toupper(argv[1][k]);
                    }
                }

        }
    }

    // Print result
    printf("%s \n", ciphertext);
    return 0;
}
