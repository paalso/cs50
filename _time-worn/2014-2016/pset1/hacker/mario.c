// Hacker's version
// http://docs.cs50.net/problems/mario/more/mario.html
// https://cdn.cs50.net/2014/fall/psets/1/hacker1/hacker1.html#itsa_mario

#include <stdio.h>
#include "cs50.h"   

void print_chars(char c, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
}

int main(void)
{

    char sharp = '#';
    char blank = ' ';
    int n;

    do {
        printf("Height: ");
        n = GetInt();
        if (n == 0)
            return 0;
    } while ((n < 1) || (n > 23));


    for (int i = 1; i <= n; ++i) {
        print_chars(blank, n - i);
        print_chars(sharp, i);
        print_chars(blank, 2);
        print_chars(sharp, i);
        printf("\n");        
    }
 
    return 0;
}