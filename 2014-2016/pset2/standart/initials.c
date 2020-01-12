// https://cdn.cs50.net/2014/fall/psets/2/pset2/pset2.html#initializing
// http://cdn.cs50.net/2016/x/psets/2/pset2/pset2.html#initializing

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"


// MAIN
int main(int argc, char* argv[])
{
    bool lookingForWord = true;
    int k = 0;
    string s, result = "";
    // printf("Enter a string\n");
    s = GetString();
    for (int i = 0, len = strlen(s); i < len; ++i) {
        if (s[i] != ' ') {
            if (lookingForWord) {
                lookingForWord = false;
                printf("%c",toupper(s[i]) );
            } 
        } else {
                lookingForWord = true;
        }
    }
    printf("\n");
}