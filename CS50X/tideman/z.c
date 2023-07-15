#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int string[] = {9, 5, 6, 7, 8, 3, 2, 4, 1, 0};

    // sort function
    int temp;
    for (int j = 0; j < 9; j++)
    {
    for (int i = 0; i < 9; i++)
    {
        if ( string[i] < string[i+1])
        {
            temp = string[i+1];
            string[i+1] = string[i];
            string[i] = temp;
        }
    }
    }
    for (int i = 0; i < 10 ; i++)
    {
        printf("%i,", string[i]);
    }
    printf("\n");
}


// Recursive function to check if entry makes a circle
bool is_circle(int cycle_start, int loser)
{
    if (loser == cycle_start)
    {
        // If the current loser is the cycle start
        // The entry makes a circle
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (makes_circle(cycle_start, i))
            {
                // Forward progress through the circle
                return true;
            }
        }
    }
    return false
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs()
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!makes_circle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the pair unless it makes a circle
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}




for (int c = 0; c < candidate_count; c++)
            {
                int scr = 0;
                for (int r = 0; r < candidate_count; r++)
                {
                    scr = scr + locked[r][c];
                }
                if (scr == 0 && tie == 1)
                {
                    printf("%s\n", candidates[c]);
                }

            }




int tie = 0;
    for (int column = 0; column < candidate_count; column++)
    {
        int score = 0;
        for (int row = 0; row < candidate_count; row++)
        {
            score = score + locked[row][column];
        }
        if (score == 0)
        {
            tie++;
        }
    }