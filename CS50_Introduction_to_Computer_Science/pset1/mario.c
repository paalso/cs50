/**
 * mario.c
 *
 * CS50 Problem Set 1: Mario
 *
 * Prints out a pyramid of a specified height
 */

#include <cs50.h>
#include <stdio.h>

const char SHARP = '#';
const char BLANC = ' ';
const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 8;

void chart(char c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        putchar(c);
    }
}

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while ((n < MIN_HEIGHT) || (n > MAX_HEIGHT));

    for (int i = 1; i <= n; ++i)
    {
        chart(BLANC, n - i);
        chart(SHARP, i);
        chart(BLANC, 2);
        chart(SHARP, i);
        printf("\n");
    }
    return 0;
}
