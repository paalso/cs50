// "More comfortable" task
// https://cs50.harvard.edu/x/2020/psets/2/substitution/

// Substitution
// =============
// Implement a program that implements a substitution cipher.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

#define NO_ERRORS 0
#define ERROR_LEN 1
#define ERROR_NON_ALPHA 2
#define ERROR_REPEAT 3


// Prototypes
int check_key(string, string);
string string_encrypt(string, string, string);
int *get_encrypt_chart(string, string);
int count_symbol(string, char);


// MAIN
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int check_key_result = check_key(key, ALPHABET);

    if (check_key_result == ERROR_LEN)
    {
        printf("Key must contain %lu characters.\n", strlen(ALPHABET));
        return 1;
    }
    else if (check_key_result == ERROR_NON_ALPHA)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    else if (check_key_result == ERROR_REPEAT)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string input = get_string("plaintext: ");
    printf("ciphertext: %s\n", string_encrypt(input, key, ALPHABET));
    return 0;
}

// Functions
int check_key(string key, string alphabet)
{
    int alphabet_len = strlen(alphabet);
    if (strlen(key) != alphabet_len)
    {
        return ERROR_LEN;
    }

    for (int i = 0; i < alphabet_len; ++i)
    {
        if (! isalpha(key[i]))
        {
            return ERROR_NON_ALPHA;
        }
    }

    for (int i = 0; i < alphabet_len; ++i)
    {
        if (count_symbol(key, alphabet[i]) > 1)
        {
            return ERROR_REPEAT;
        }
    }

    return NO_ERRORS;
}


int *get_encrypt_chart(string key, string alphabet)
{
    int len = strlen(alphabet);
    int *encrypt_chart = (int *) malloc(len * sizeof(char));

    for (int i = 0; i < len; ++i)
    {
        encrypt_chart[i] = tolower(key[i]) - alphabet[i];
    }
    return encrypt_chart;
}


string string_encrypt(string input, string key, string alphabet)
{
    int len = strlen(input);
    string output = (string) malloc(len * sizeof(char) + 1);
    int *encrypt_chart = get_encrypt_chart(key, alphabet);
    for (int i = 0; i < len; ++i)
    {
        char c = input[i];
        if (! count_symbol(alphabet, c))
        {
            output[i] = c;
        }
        else if (tolower(c) == c)
        {
            output[i] = c + encrypt_chart[c - 'a'];
        }
        else
        {
            output[i] = c + encrypt_chart[c - 'A'];

        }

    }
    output[len] = '\0';
    return output;
}


int count_symbol(string text, char symbol)
{
    char c;
    int i = 0;
    int counter = 0;
    while ((c = text[i++]) != '\0')
    {
        if (symbol == tolower(c))
        {
            counter += 1;
        }
    }
    return counter;
}