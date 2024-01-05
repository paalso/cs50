/**
 * caesar.c
 *
 * Computer Science 50
 * Problem Set 2
 *
 * Encrypts messages using Caesar’s cipher
 *
 * 2020:
 * https://cs50.harvard.edu/x/2020/psets/2/caesar/
 * 2019:
 * https://lab.cs50.io/cs50/labs/2019/x/caesar/
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Prototypes
char charCaesarEncrypt(char, int);
string stringCaesarEncrypt(string, int);

// MAIN
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string input = get_string("plaintext: ");

    printf("ciphertext: %s\n", stringCaesarEncrypt(input, key));
    return 0;
}

// -------------------------------------------------------
// Functions
char charCaesarEncrypt(char c, int key)
{
    int shiftedC = c + key % 26;

    if (islower(c))
    {
        return 'a' + (shiftedC - 'a') % 26;
    }
    if (isupper(c))
    {
        return 'A' + (shiftedC - 'A') % 26;
    }
    return c;
}

string stringCaesarEncrypt(string input, int key)
{
    int len = strlen(input);
    string output = (string) malloc(len * sizeof(char) + 1);
    for (int i = 0; i < len; ++i)
    {
        output[i] = charCaesarEncrypt(input[i], key);
    }
    output[len] = '\0';
    return output;
}
