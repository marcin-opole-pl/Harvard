#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 3

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

int main(void)
{
    pair_count = 0;

    preferences[0][0] = 0;
    preferences[0][1] = 7;
    preferences[0][2] = 3;
    preferences[1][0] = 2;
    preferences[1][1] = 0;
    preferences[1][2] = 5;
    preferences[2][0] = 6;
    preferences[2][1] = 4;
    preferences[2][2] = 0;

    printf("Preferences:\n");
    for (int l = 0; l < MAX; l++)
    {
        for (int m = 0; m < MAX; m++)
        {
            printf("%i", preferences[l][m]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    candidate_count = 3;

    // Function pair
    for (int row = 0; row < candidate_count; row++)
    {
        for (int column = row + 1; column < candidate_count; column++)
        {
             if (preferences[row][column] > preferences[column][row])
            {
                pairs[pair_count].winner = row;
                pairs[pair_count]. loser = column;
                pair_count++;
                //printf("winner: %i", row); //temp
                //printf("loser: %i", column); //temp
            }
            else if (preferences[row][column] < preferences[column][row])
            {
                pairs[pair_count].winner = column;
                pairs[pair_count]. loser = row;
                pair_count++;
                //printf("winner: %i", column); //temp
                //printf("loser: %i", row); // temp
            }
        }

    }

    // Temp print unsorted pairs
    printf("\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("winner: %i\n", pairs[i].winner);
        printf("loser: %i\n\n", pairs[i].loser);
    }

    // Function sort pairs
    int temp_winner;
    int temp_loser;
    for (int j = 0; j < pair_count; j++)
    {
        for (int i = 0; i < pair_count; i++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i+1].winner][pairs[i+1].loser])
            {
                temp_winner = pairs[i+1].winner;
                temp_loser = pairs[i+1].loser;
                pairs[i+1].winner = pairs[i].winner;
                pairs[i+1].loser = pairs[i].loser;
                pairs[i].winner = temp_winner;
                pairs[i].loser = temp_loser;
            }

        }
    }
    // Temp prrint sorted pairs
    printf("SORTED:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("winner: %i\n", pairs[i].winner);
        printf("loser: %i\n\n", pairs[i].loser);
    }

    // Function lock pairs
// Zeros locked 2d array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            // Temp locked 0000 print
           // printf("%i ", locked[i][j]);
        }
    // Temp
   // printf("\n");
    }

    // Lock candidates


    locked[pairs[0].winner][pairs[0].loser] = true;
    locked[pairs[1].winner][pairs[1].loser] = true;
    for (int q = 1; q < pair_count; q++)
    {
        for (int r = 0; r < q - 2; r++)
        {
            if (pairs[q].loser != pairs[r].winner)
            {
                locked[pairs[q].winner][pairs[q].loser] = true;
            }
        }
    }




    // Temp locked print

    for (int column = 0; column < candidate_count; column++)
    {
        int score = 0;
        for (int row = 0; row < candidate_count; row++)
        {
            score = score + locked[row][column];
        }
        if (score == 0)
        {
            printf("%s\n", candidates[column]);
        }
        else
        {
            break;
        }
    }



}