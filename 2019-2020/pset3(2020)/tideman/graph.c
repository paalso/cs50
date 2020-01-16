// Вспомогательный файл, в к-м разрабатывалась функция check_cycle - 
// проверки отсутствия цикла при добавлении очередного ребра

#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

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
void print_locked();
void print_array(int array[], int size);
bool check_cycle(int x, int y);
void fill_array(int array[], int size, int filler);
void copy_array(int from[], int to[], int size, int pos_to_copy, int filler);

int main(int argc, string argv[])
{
    candidate_count = 4;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // Test Set 1
    // locked[0][1] = true;
    // locked[2][0] = true;
    // locked[2][3] = true;
    // locked[3][0] = true;
    // locked[3][1] = true;
    // printf("Cycle: %d\n", check_cycle(1, 2));

    // Test Set 2

    locked[2][1] = true;
    locked[1][0] = true;
    locked[0][3] = true;
    print_locked();
    printf("Cycle: %d\n", check_cycle(3, 2));

    return 0;
}



void print_locked()
{
    for (int i = 0; i < candidate_count; ++i)
    {
        for (int j = 0; j < candidate_count; ++j)
        {
            printf("%d ", locked[i][j]);
        }
        printf("\n");
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


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

// bool check_dfs(int row, int col)
// {
//     for (int i = 0; i < candidate_count; ++i)
//     {
//         if (locked[col][i])
//         {
//             printf("%d %d\n", col, i);
//             if (i == row)
//             {
//                 return true;
//             }
//             if (check_dfs(i, row))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }