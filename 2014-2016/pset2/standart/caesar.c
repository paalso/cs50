// https://cdn.cs50.net/2014/fall/psets/2/pset2/pset2.html#hail_caesar
// http://cdn.cs50.net/2016/x/psets/2/pset2/pset2.html#hail_caesar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

char charCaesarEncrypt(char, int);

// MAIN
int main(int argc, char* argv[])
{

    if (argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    string input = GetString();
    int key = atoi(argv[1]);

    for (int i = 0, len = strlen(input); i < len; ++i) {
        printf("%c",charCaesarEncrypt(input[i], key));
    }
    printf("\n");
    return 0;
}

char charCaesarEncrypt(char c, int key){
    int shiftedC = c + key % 26;

    if (islower(c))
        return 'a' + (shiftedC - 'a') % 26;
    if (isupper(c))
        return 'A' + (shiftedC - 'A') % 26;

    return c;
}