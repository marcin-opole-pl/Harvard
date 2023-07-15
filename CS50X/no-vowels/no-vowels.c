// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, string argv[])
{
// Check if lenght of command-lin is correct
    if (argc != 2)
    {
        printf("One command-line arguent please\n");
        return 1;
    }
//
    else
    {
        string out = replace(argv[1]);
        printf("%s\n", out);
    }
}
string replace(string word)
{
    // Determinate lenght of agrv
    int str_len = strlen(word);
    string input = word;
    string output = input;
    for (int i = 0; i < strlen(word); i++)
    {
// Switch char
        switch (input[i])
        {
            case 'a':
                output[i] = '6';
                break;
            case 'e':
                output[i] = '3';
                break;
            case 'i':
                output[i] = '1';
                break;
            case 'o':
                output[i] = '0';
                break;
            default:
                output[i] = input[i];
                break;
            }
    }
    return output;
}