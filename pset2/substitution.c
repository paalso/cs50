/**
 * substitution.c
 *
 * CS50 Problem Set 2: Substitution
 *
 * Encrypts the text using a substitution cipher
 */

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define ALPHABET_LENGTH strlen(ALPHABET)

int checkArgs(int, string[]);
bool isValidChar(char c);
bool checkKeyLength(const string);
bool checkArgsNumber(int);
bool areValidChars(const string);
bool areCharsUniq(const string);

char encryptChar(char, string, string);
string encryptText(string, string);
void toLowerText(string);

int main(int argc, char *argv[])
{
    int checkArgsCode = checkArgs(argc, argv);
    if (checkArgsCode)
        return checkArgsCode;

    string key = argv[1];
    toLowerText(key);
    string text = get_string("plaintext: ");
    string ciphertext = encryptText(text, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// ----- Args check ---------------------------------------
int checkArgs(int argc, char *argv[])
{
    if (!checkArgsNumber(argc))
    {
        fprintf(stderr, "Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!checkKeyLength(key))
    {
        fprintf(stderr, "Error: Key must contain exactly %lu characters.\n", ALPHABET_LENGTH);
        return 1;
    }

    if (!areValidChars(key))
    {
        fprintf(stderr, "Key must contain alphabetic characters only.\n");
        return 1;
    }

    if (!areCharsUniq(key))
    {
        fprintf(stderr, "Key must contain uniq characters only.\n");
        return 1;
    }

    return 0;
}

bool checkArgsNumber(int argc)
{
    return argc == 2;
}

bool checkKeyLength(const string key)
{
    return strlen(key) == ALPHABET_LENGTH;
}

bool areValidChars(const string text)
{
    const char *c = text;
    while (*c != '\0')
    {
        if (!isValidChar(*c++))
            return false;
    }
    return true;
}

bool isValidChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool areCharsUniq(const string text)
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

// ----- Encrypting ---------------------------------------
void toLowerText(string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; ++i)
        text[i] = tolower(text[i]);
}

char encryptChar(char c, string alphabet, string key)
{
    char *position = strchr(alphabet, tolower(c));
    if (position)
    {
        int index = position - alphabet;
        char encryptedChar = key[index];
        if (isupper(c))
            encryptedChar = toupper(encryptedChar);
        return encryptedChar;
    }
    return c;
}

string encryptText(string text, string key)
{
    int len = strlen(text);
    string encrypted = (string) malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; ++i)
    {
        encrypted[i] = encryptChar(text[i], ALPHABET, key);
    }
    encrypted[len] = '\0';
    return encrypted;
}
