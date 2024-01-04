/**
 * vigenere.c
 *
 * Computer Science 50
 * Problem Set 2
 *
 * Encrypts messages using Vigenère’s cipher
 *
 * 2019:
 * https://lab.cs50.io/cs50/labs/2019/x/vigenere/
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Prototypes
char charCaesarEncrypt(char, int);
string stringVigenereEncrypt(string, string);

// MAIN
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    string keyWord = argv[1];
    
    char c;
    for (int i = 0; (c = keyWord[i]) != '\0'; ++i)
    {
        if (!isalpha(c))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }    
    }
    
    string input = get_string("plaintext: ");
            
    printf("ciphertext: %s\n", stringVigenereEncrypt(input, keyWord));
    return 0;
}

// Functions
// -------------------------------------------------------
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

// ----------------------------------------------------------
string stringVigenereEncrypt(string input, string keyWord)
{
    int len = strlen(input);
    int lenKeyWord = strlen(keyWord);
    string output = (string) malloc(len * sizeof(char) + 1);
       
    for (int i = 0, j = 0; i < len; ++i)
    {
        if (j == lenKeyWord)
        {
            j = 0;
        }
        output[i] = charCaesarEncrypt(input[i], tolower(keyWord[j]) - 'a');
        
        if (isalpha(input[i]))
        {
            ++j;
        }
    }
    output[len] = '\0'; 
    return output;
}