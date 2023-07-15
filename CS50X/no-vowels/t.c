// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string word = (get_string("word please: "));


// Determinate lenght of agrv
    int str_len = strlen(word);
    string input = word;
    string output = input;
    for (int i = 0; i < strlen(word); i++)
    {
// Char to lower
        char c = tolower(input[i]);
// Switch char
            switch (c)
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
                    output[i] = c;
                    break;
            }
    }
    printf("%s\n", output);
}
