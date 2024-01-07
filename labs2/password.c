/**
 * no-vowels.c
 *
 * CS50 Practice Problems 2: Password
 *
 * Checks the password to contain at least one uppercase letter,
 * lowercase letter, number and symbol
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

bool checkPassword(string password)
{
    const string symbols = "%!\"#$&\'()*+,-./:;<=>?@[\\]^_`{|}~";

    bool containsLowerCaseLetters = false;
    bool containsUpperCaseLetters = false;
    bool containsDigits = false;
    bool containsSymbols = false;

    char *c = password;
    while (*c != '\0')
    {
        if (isupper(*c))
            containsUpperCaseLetters = true;
        if (islower(*c))
            containsLowerCaseLetters = true;
        if (isdigit(*c))
            containsDigits = true;
        if (strchr(symbols, *c))
            containsSymbols = true;
        c++;
    }
    return containsUpperCaseLetters && containsLowerCaseLetters && containsDigits && containsSymbols;
}
