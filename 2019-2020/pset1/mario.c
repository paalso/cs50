/**
 * mario.c
 *
 * Computer Science 50
 * Problem Set 1
 *
 * Prints out a half-pyramid of a specified height
 *
 * 2019:
 * https://lab.cs50.io/cs50/labs/2019/x/mario/less/
 * 2020:
 * https://lab.cs50.io/cs50/labs/2020/x/mario/less/
 *
 */

#include <stdio.h>
#include <cs50.h>

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
        printf("\n");        
    }
    return 0;
}
