/**
 * no-vowels.c
 *
 * CS50 Practice Problems 2: Hours
 *
 * Leet vowels in a given text with the specified ones:
 * a -> 6, e -> 3, i -> 1, o -> 0, u -> u
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOWELS_SIZE 5
char VOWELS[VOWELS_SIZE] = {'a', 'e', 'i', 'o', 'u'};
char VOWELS_SUBS[VOWELS_SIZE] = {'6', '3', '1', '0', 'u'};

string substitute(string, char *, char *);
int findChar(const char *, int, char);
char сharSub(char, int, char *, char *);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: no-vowels text\n");
        return 1;
    }

    string input = argv[1];
    string processed = substitute(input, VOWELS, VOWELS_SUBS);
    printf("%s\n", processed);
}

string substitute(char *text, char *charsToSub, char *charsSubs)
{
    int size = strlen(text);
    string result = malloc((size + 1) * sizeof(char));
    for (int i = 0; i <= size; i++)
    {
        char substitution = сharSub(text[i], VOWELS_SIZE, VOWELS, VOWELS_SUBS);
        result[i] = substitution;
    }
    result[size] = '\0';
    
    return result;
}

int findChar(const char *chars, int size, char c)
{
    for (int i = 0; i < size; i++)
    {
        if (chars[i] == c)
            return i;
    }
    return -1;
}

char сharSub(char c, int charsToSubSize, char *charsToSub, char *charsSubs)
{
    int idInCharsToSub = findChar(charsToSub, charsToSubSize, c);
    if (idInCharsToSub >= 0)
        return charsSubs[idInCharsToSub];
    return c;
}
