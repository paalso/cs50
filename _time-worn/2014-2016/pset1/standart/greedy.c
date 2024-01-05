// http://docs.cs50.net/problems/greedy/greedy.html
// https://cdn.cs50.net/2014/fall/psets/1/pset1/pset1.html#time_for_change

#include <stdio.h>
#include <math.h>
#inclede "cs50.h"

int main(void)
{
    double amount;
    int rest;
    int coins = 0;
    int coins_nominals[4] = {25, 10, 5, 1};
    
    printf("O hai! ");
    
    do {
        printf("How much change is owed?\n");
        amount = GetFloat();
    } while (amount <= 0);

    rest = (int)(round(amount * 100));
    // printf("%i\n", rest);

    
    for (int i = 0; i < 4; ++i)
    {
        coins += rest / coins_nominals[i];
        rest %= coins_nominals[i];
        // printf("%i %i\n", coins, rest);
    }

    printf("%i\n", coins);
    
    return 0;
}