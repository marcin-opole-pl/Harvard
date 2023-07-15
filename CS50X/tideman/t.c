#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

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

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
        // TEMP
        printf("Ranks: ");
        for (int k = 0; k < candidate_count; k++)
        {
            printf("%i", ranks[k]);
        }
        printf("\n");
        printf("\n");
        printf("Preferences:\n");
        for (int l = 0; l < candidate_count; l++)
        {
            for (int m = 0; m < candidate_count; m++)
            {
                printf("%i", preferences[l][m]);
            }
            printf("\n");
        }
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
   // Reset temp
    int temp[MAX];
    for (int i = 0; i < MAX; i++)
    {
        temp[i] = 0;
    }
    // Make pref
    for (int k = 0; k < candidate_count; k++) // Rank[k]
    {
        for (int row = 0; row < candidate_count; row++) // Candidate[i]
        {
            if (ranks[k] == row)
            {
                temp[row] = 1;
                for (int column = 0; column < candidate_count; column++)
                {
                    if (temp[column] == 0)
                    {
                        preferences[row][column]++;
                    }
                }
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int row = 0; row < candidate_count; row++)
    {
        for (int column = row + 1; column < candidate_count; column++)
        {
             if (preferences[row][column] > preferences[column][row])
            {
                pairs[pair_count].winner = row;
                pairs[pair_count]. loser = column;
                pair_count++;
                printf("winner: %i ", row); //temp
                printf("loser: %i  ", column); //temp
            }
            else if (preferences[row][column] < preferences[column][row])
            {
                pairs[pair_count].winner = column;
                pairs[pair_count]. loser = row;
                pair_count++;
                printf("winner: %i ", column); //temp
                printf("loser: %i  ", row); // temp
            }
        }

    }

    // Temp print unsorted pairs
    printf("\n\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("winner: %i\n", pairs[i].winner);
        printf("loser: %i\n\n", pairs[i].loser);
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
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

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Zeros locked 2d array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {

            // Temp locked 0000 print
           printf("%i ", locked[i][j]);
        }
    // Temp
   printf("\n");
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





    // Temp loced print
    printf("locked: \n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", locked[i][j]);
        }
    // Temp
    printf("\n");
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
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
    return;
}