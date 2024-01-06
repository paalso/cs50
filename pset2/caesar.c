/**
 * caesar.c
 *
 * CS50 Problem Set 2: Caesar
 *
 * Encrypts the text using Caesar’s cipher algorithm
 */

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char charCaesarEncrypt(char, int);
string stringCaesarEncrypt(string, int);
bool onlyDigits(string);

int main(int argc, char *argv[])
{
    string arg = argv[1];
    if (argc != 2 || !onlyDigits(arg))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(arg);
    string input = get_string("plaintext: ");
    string ciphertext = stringCaesarEncrypt(input, key);

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);
    return 0;
}

char charCaesarEncrypt(char c, int key)
{
    if (!isalpha(c))
        return c;

    char startChar = islower(c) ? 'a' : 'A';
    int shiftedC = c + key % 26;
    return startChar + (shiftedC - startChar) % 26;
}

string stringCaesarEncrypt(string input, int key)
{
    int len = strlen(input);
    string output = (string) malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; ++i)
        output[i] = charCaesarEncrypt(input[i], key);
    output[len] = '\0';
    return output;
}

bool onlyDigits(string s)
{
    char *c = s;
    while (*c != '\0')
    {
        if (!isdigit(*c++))
            return false;
    }
    return true;
}
