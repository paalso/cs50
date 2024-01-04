// http://docs.cs50.net/problems/mario/less/mario.html
// https://cdn.cs50.net/2014/fall/psets/1/pset1/pset1.html#itsa_mario


#include <stdio.h>
#include "cs50.h"

void print_chars(char c, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
}

int main(void)
{

    const char sharp = '#';
    const char blank = ' ';
    int n;

    do {
    	printf("Height: ");
        n = GetInt();
        if (n == 0)
        	return 0;
    } while ((n < 1) || (n > 23));


    for (int i = 1; i <= n; ++i) {
        print_chars(blank, n - i);
        print_chars(sharp, i + 1);
        printf("\n");        
    }
 
    return 0;
}