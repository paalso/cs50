/**
 * prime.c
 *
 * CS50 Practice Problems 1: Half
 *
 * Calculate your half of a restaurant bill
 */

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int);

int main(void)
{
    int from = get_int("Minimum: ");
    int to = get_int("Maximum: ");

    for (int i = from; i <= to; i++)
    {
        if (isPrime(i))
            printf("%d\n", i);
    }

    return 0;
}

bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    for (int i = 3, upperBound = (int) sqrt(n); i <= upperBound; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
