/**
 * caesar.c
 *
 * CS50 Problem Set 2: Caesar
 *
 * Encrypts the text using Caesar’s cipher algorithm
 */

#define CIPHER_CHARS_NUMBER 26

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkKeyLength(const char *);
bool checkArgsNumber(int);
bool isAlphaText(const char *);
bool areCharsUniq(const char *);

int main(int argc, char *argv[])
{
    if (!checkArgsNumber(argc))
    {
        fprintf(stderr, "Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!checkKeyLength(key))
    {
        fprintf(stderr, "Key must contain 26 characters.\n");
        return 1;
    }

    if (!isAlphaText(key))
    {
        fprintf(stderr, "Key must contain alphabetic characters only.\n");
        return 1;
    }

    if (!areCharsUniq(key))
    {
        fprintf(stderr, "Key must contain uniq characters only.\n");
        return 1;
    }

    printf("Your args are valid!\n");
    return 0;
}

bool checkArgsNumber(int argc)
{
    return argc == 2;
}

bool checkKeyLength(const char *key)
{
    return strlen(key) == CIPHER_CHARS_NUMBER;
}

bool isAlphaText(const char *text)
{
    const char *c = text;
    while (*c != '\0')
    {
        if (!isalpha(*c++))
            return false;
    }
    return true;
}

bool areCharsUniq(const char *text)
{
    int size = strlen(text);
    for (int i = 0; i < size - 1; i++)
    {
        char c = tolower(text[i]);
        for (int j = i + 1; j < size; j++)
            if (tolower(text[j]) == c)
                return false;
    }
    return true;
}
