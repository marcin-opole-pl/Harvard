#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9
int preferences[MAX][MAX];

int main(void)
{
    int ranks[] = { 8, 0, 7, 1, 6, 2, 5, 3, 4};
    int candidate_count = MAX;

    printf("\n");
    printf("\n");

    printf("Ranks: ");
    for (int k = 0; k < candidate_count; k++)
    {
        printf("%i", ranks[k]);
    }
    printf("\n");
    printf("\n");

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    printf("Preferences1:\n");
    for (int l = 0; l < candidate_count; l++)
    {
        for (int m = 0; m < candidate_count; m++)
        {
            printf("%i", preferences[l][m]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Reset preferences
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }




    // Reset temp
    int temp[MAX];
    for (int i = 0; i < MAX; i++)
    {
        temp[i] = 0;
    }
    // Make pref2
    for (int k = 0; k < candidate_count; k++) // Rank[k]
    {
        for (int i = 0; i < candidate_count; i++) // Candidate[i]
        {
            if (ranks[k] == i)
            {
                temp[i] = 1;
                for (int j = 0; j < candidate_count; j++)
                {
                    if (temp[j] == 0)
                    {
                        preferences[i][j] = 1;
                    }
                }
            }
        }
    }




    // Print temp
    printf("Temp: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("%i", temp[i]);
    }

    printf("\n");
    printf("\n");

    // Print pref2
    printf("Preferences2:\n");
    for (int l = 0; l < candidate_count; l++)
    {
        for (int m = 0; m < candidate_count; m++)
        {
            printf("%i", preferences[l][m]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
}