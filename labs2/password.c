/**
 * no-vowels.c
 *
 * CS50 Practice Problems 2: Password
 *
 * Checks the input password to contain at least
 * one uppercase letter, lowercase letter, number and symbol
 */

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool checkPassword(string);
bool checkLowerCaseLetters(string);
bool checkUpperCaseLetters(string);
bool checkDigits(string);
bool checkSymbols(string);

int main(int argc, char *argv[])
{
    string password = get_string("Enter your password: ");

    if (!checkPassword(password))
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
    else
        printf("Your password is valid!\n");

    return 0;
}

// ----- Args check ---------------------------------------
bool checkPassword(string password)
{
    if (!checkLowerCaseLetters(password))
        return false;
    if (!checkUpperCaseLetters(password))
        return false;
    if (!checkDigits(password))
        return false;
    if (!checkSymbols(password))
        return false;
    return true;
}

bool checkUpperCaseLetters(string text)
{
    char *c = text;
    while (*c != '\0')
        if (isupper(*c++))
            return true;
    return false;
}

bool checkDigits(string text)
{
    char *c = text;
    while (*c != '\0')
        if (isdigit(*c++))
            return true;
    return false;
}

bool checkLowerCaseLetters(string text)
{
    char *c = text;
    while (*c != '\0')
        if (islower(*c++))
            return true;
    return false;
}

bool checkSymbols(string text)
{
    const string symbols = "%!\"#$&\'()*+,-./:;<=>?@[\\]^_`{|}~";

    char *c = text;
    while (*c != '\0')
        if (strchr(symbols, *c++))
            return true;
    return false;
}
