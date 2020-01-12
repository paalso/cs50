// https://cdn.cs50.net/2014/fall/psets/2/pset2/pset2.html#parlez_vous_fran%C3%A7ais
// http://cdn.cs50.net/2016/x/psets/2/pset2/pset2.html#parlez_vous_français

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

// bool isAlphaWord(string word);
char charCaesarEncrypt(char, int);

// MAIN
int main(int argc, char* argv[])
{

    if (argc != 2) {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string keyWord = argv[1];
    int lenKeyWord = strlen(keyWord);

    for (int i = 0; i < lenKeyWord; ++i)
        if(!isalpha(keyWord[i])) {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    
    string input = GetString();
    int j = 0;  // Индекс перебора символов в ключевом слове


    for (int i = 0, len = strlen(input); i < len; ++i) {
        if (j == lenKeyWord)
            j = 0;
        printf("%c",charCaesarEncrypt(input[i],tolower(keyWord[j]) - 'a'));
        if (isalpha(input[i]))
            ++j;
    }
    printf("\n");
    return 0;
}

// SUPPLYING ROUTINES

// bool isAlphaWord(string word) {
//     for (int i = 0, len = strlen(word); i < len; ++i) {
//         if (! isalpha(word[i])) {
//             return false;
//         }
//         return true;
//     }
// }

char charCaesarEncrypt(char c, int n){
    int shiftedC = c + n % 26;
    if (islower(c))
        return 'a' + (shiftedC - 'a') % 26;
    if (isupper(c))
        return 'A' + (shiftedC - 'A') % 26;
    return c;
}