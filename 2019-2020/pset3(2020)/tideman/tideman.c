#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// Additional functions
void print_ranks(int ranks[]);
void print_preferences();
void print_pairs();
int pairs_comparator(const void *val1, const void *val2);
bool check_cycle(int x, int y);
void fill_array(int array[], int size, int filler);
void copy_array(int from[], int to[], int size, int pos_to_copy, int filler);

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

    // print_preferences();    // DEBUG

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

        // printf("Voter # %d\n", i);   // DEBUG
        // print_ranks(ranks);   // DEBUG

        record_preferences(ranks);

        // print_preferences();    // DEBUG

        printf("\n");
    }

    print_preferences();    // DEBUG

    add_pairs();

    // print_pairs();   // DEBUG

    sort_pairs();

    // print_pairs();   // DEBUG

    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; ++i)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[i] = rank;
            return true;
        }
    }
    return false;
}


// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; ++i)
    {
        for (int j = i + 1; j < candidate_count; ++j)
        {
            if (ranks[j] < ranks[i])
            {
                preferences[j][i] += 1;
            }
            else
            {
                preferences[i][j] += 1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int is_even_candidate_count = candidate_count % 2 + 1;
    for (int i = 0; i < candidate_count - 1; ++i)
    {
        for (int j = i + 1; j < candidate_count; ++j)
        {
            if (is_even_candidate_count && preferences[i][j] == preferences[j][i])
            {
                continue;
            }
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
            }
            else
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
            }
            pair_count += 1;
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    qsort(pairs, pair_count, sizeof(pair), pairs_comparator);
    return;
}

// Comparator function of qsort for sort_pairs
int pairs_comparator(const void *val1, const void *val2)
{
    pair *pair1 = (pair *)val1;
    pair *pair2 = (pair *)val2;
    return preferences[pair2->winner][pair2->loser] -
            preferences[pair1->winner][pair1->loser];
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; ++i)
    {
        int row = pairs[i].winner;
        int col = pairs[i].loser;
        if (!check_cycle(row, col))
        {
            locked[row][col] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool flag;
    for (int j = 0; j < candidate_count; ++j)
    {
        flag = true;
        for (int i = 0; i < candidate_count; ++i)
        {
            if (locked[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            {
                printf("%s\n", candidates[j]);
                return;
            }
    }
    return;
}

// Checks if there would be created a cycle in the array 'locked'
// when add new edge (row, col)
// Очень корявая и громоздкая функция, - проще не получилось
// (учи алгортимы на графах, бля!), но, вроде бы, работает
bool check_cycle(int row, int col)
{

    int check_list0[candidate_count];
    int check_list[candidate_count];

    fill_array(check_list0, candidate_count, -1);
    fill_array(check_list, candidate_count, -1);
    int check_list0_len = 1;
    int check_list_len = 0;

    check_list0[0] = col;

    while (true)
    {
        for (int i = 0; i < check_list0_len; ++i)
        {
            for (int j = 0; j < candidate_count; ++j)
            {
                if (locked[check_list0[i]][j])
                {
                    if (j == row) // ?
                    {
                        return true;
                    }
                    check_list[check_list_len] = j;
                    check_list_len += 1;
                }
            }
            if (! check_list_len)
            {
                return false;
            }
        }

        copy_array(check_list, check_list0, candidate_count, check_list_len, -1);
        check_list0_len = check_list_len;
        fill_array(check_list, candidate_count, -1);
        check_list_len = 0;
    }
    return false;
}

// Additional functions, for 'check_cycle()'
void fill_array(int array[], int size, int filler)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = filler;
    }
}

void copy_array(int from[], int to[], int size, int pos_to_copy, int filler)
{
    fill_array(to, size, filler);
    for (int i = 0; i < pos_to_copy; ++i)
    {
        to[i] = from[i];
    }
}


// Additional functions, for debug printing of the data structures in the program

// Print the array ranks[]
void print_ranks(int ranks[])
{
    for (int i = 0; i < candidate_count; ++i)
    {
        printf("%d ", ranks[i]);
    }
    printf("\n");
}

// Print the array preferences[][]
void print_preferences()
{
    printf("\n");
    for (int i = 0; i < candidate_count; ++i)
    {
        for (int j = 0; j < candidate_count; ++j)
        {
            printf("%d ", preferences[i][j]);
        }
        printf("\n");
    }
}

// Print the array pairs[][]
void print_pairs()
{
    for (int i = 0; i < pair_count; ++i)
    {
        printf("(%d, %d), victory strength: %d\n",
            pairs[i].winner, pairs[i].loser, preferences[pairs[i].winner][pairs[i].loser]);
    }
    printf("\n");
}