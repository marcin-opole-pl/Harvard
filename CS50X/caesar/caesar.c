#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string rotate(string text, int l);
int main(int argc, string argv[])
{
    // Check if one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check if argument is not a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv ASCII to int
    int j = atoi(argv[1]);
    // Set real roatation value (max 25)
    int l = j % 26;
    // Get text form user
    string text = get_string("plaintext:  ");
    // Print ciphertext
    printf("ciphertext: ");
    string cipher = rotate(text, l);
    printf("%s\n", cipher);
    return 0;

}
string rotate(string text, int l)
{
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if char is alphabetical
        if (isalpha(text[i]))
        {
            // If uppercase
            if (isupper(text[i]))
            {
                // Set A value to 0 (offset all Cap letters by 65)
                text[i] = text[i] - 65;
                // Rotate text by l
                text[i] = (text[i] + l) % 26;
                // Return to original value
                text[i] = text[i] + 65;
            }
            // If lowercase
            else
            {
                // Set a value to 0 (offset all lower letters by 97)
                text[i] = text[i] - 97;
                // Rotate text by l
                text[i] = (text[i] + l) % 26;
                // Return to original value
                text[i] = text[i] + 97;
            }
        }
        // If char is non-alphabetical
        else
        {
            text[i] = text[i];
        }
    }
    return text;
}