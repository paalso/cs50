/**
 * cash.c
 *
 * CS50 Problem Set 1: Cash
 *
 * This program calculates the minimum number of quarters, dimes, nickels,
 * and pennies needed to make change for a user-input amount.
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int rest;
    int coins = 0;
    int coins_nominals[4] = {25, 10, 5, 1};

    do
    {
        rest = get_int("Change owed: ");
    }
    while (rest < 0);

    for (int i = 0; i < 4; ++i)
    {
        coins += rest / coins_nominals[i];
        rest %= coins_nominals[i];
    }

    printf("%i\n", coins);

    return 0;
}
