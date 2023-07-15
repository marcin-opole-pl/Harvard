#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");
    int l_no = count_letters(text);
    int w_no = count_words(text);
    int s_no = count_sentences(text);
    // Compute Coleman-Liau index
    float L = (float)l_no / w_no * 100;
    float S = (float)s_no / w_no * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int score = round(index);
    // Print results
    if (score < 1)
    {
        printf("Before Grade 1");
    }
    else if (score >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        for (int i = 2; i < 16 ; i++)
        {
            if (score == i)
            {
                printf("Grade %i", i);
            }
        }
    }
    printf("\n");
}
// Function that counts letter
int count_letters(string text)
{
    int l_no = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            l_no++;
        }
    }
    return l_no;
}
// Function to counts words
int count_words(string text)
{
    int w_no = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            w_no++;
        }
    }
    return w_no;
}
// Function that counts sentences
int count_sentences(string text)
{
    int s_no = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            s_no++;
        }
    }
    return s_no;
}