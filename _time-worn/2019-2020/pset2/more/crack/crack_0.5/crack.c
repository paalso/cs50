// "More comfortable" task
// https://lab.cs50.io/cs50/labs/2019/x/crack/

// This version is submitted onto and accepted by CS50:
// https://github.com/submit50/paalso/commit/fc6c52a2da16b53860dcfbb68b703404ea9f3c76?diff=unified
// But there's more perfect and efficient version - using dictionaries that search by actual words: crack_more.c

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// #include <crypt.h>

const int TOTAL_LETTERS = 52;
const char LETTERS[] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e',
                        'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j',
                        'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
                        'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 
                        'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'
                        }; 


const int TOTAL_DICTS = 3;
const char *DICTS[] = {"words_len3.dat", "words_len4.dat", "words_len4.dat"};

_Bool check1(char str[], const char *hash, const char *salt);
_Bool check2(char str[], const char *hash, const char *salt);
_Bool check3(char str[], const char *hash, const char *salt);
_Bool check4(char str[], const char *hash, const char *salt);
_Bool check5(char str[], const char *hash, const char *salt);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const char *hash = argv[1];
    char salt[] = "  ";
    salt[0] = hash[0];
    salt[1] = hash[1];

    char unogram[] = "1";
    if (check1(unogram, hash, salt))
    {
        printf("%s\n", unogram);
        return 0;
    }

    char bigram[] = "12";
    if (check2(bigram, hash, salt))
    {
        printf("%s\n", bigram);
        return 0;
    }

    char trigram[] = "123";
    if (check3(trigram, hash, salt))
    {
        printf("%s\n", trigram);
        return 0;
    }

    char tetragram[] = "1234";
    if (check4(tetragram, hash, salt))
    {
        printf("%s\n", tetragram);
        return 0;
    }

    char pentagram[] = "12345";
    if (check5(pentagram, hash, salt))
    {
        printf("%s\n", pentagram);
        return 0;
    }

    return 0;
}

// ------------------------------------------------------

_Bool check1(char str[], const char *hash, const char *salt)
{
    for (int i = 0; i < TOTAL_LETTERS; ++i)
    {
        str[0] = LETTERS[i];
        if (strcmp(crypt(str, salt), hash) == 0)
        {
            // printf("%s\n", str);
            return true;
        }
    }
    return false;
}


_Bool check2(char str[], const char *hash, const char *salt)
{
    for (int i = 0; i < TOTAL_LETTERS; ++i)
    {
        for (int j = 0; j < TOTAL_LETTERS; ++j)
        {
            str[0] = LETTERS[i];
            str[1] = LETTERS[j];
            if (strcmp(crypt(str, salt), hash) == 0)
            {
                // printf("%s\n", str);
                return true;
            }
        }
    }
    return false;
}


_Bool check3(char str[], const char *hash, const char *salt)
{
    for (int i = 0; i < TOTAL_LETTERS; ++i)
    {
        for (int j = 0; j < TOTAL_LETTERS; ++j)
        {
            for (int k = 0; k < TOTAL_LETTERS; ++k)
            {
                str[0] = LETTERS[i];
                str[1] = LETTERS[j];
                str[2] = LETTERS[k];
                if (strcmp(crypt(str, salt), hash) == 0)
                {
                    // printf("%s\n", str);
                    return true;
                }
            }
        }
    }
    return false;
}


_Bool check4(char str[], const char *hash, const char *salt)
{
    for (int i = 0; i < TOTAL_LETTERS; ++i)
    {
        for (int j = 0; j < TOTAL_LETTERS; ++j)
        {
            for (int k = 0; k < TOTAL_LETTERS; ++k)
            {
                for (int l = 0; l < TOTAL_LETTERS; ++l)
                {
                    str[0] = LETTERS[i];
                    str[1] = LETTERS[j];
                    str[2] = LETTERS[k];
                    str[3] = LETTERS[l];
                    if (strcmp(crypt(str, salt), hash) == 0)
                    {
                        // printf("%s\n", str);
                        return true;
                    }                   
                }
            }
        }
    }
    return false;
}


_Bool check5(char str[], const char *hash, const char *salt)
{
    for (int i = 0; i < TOTAL_LETTERS; ++i)
    {
        for (int j = 0; j < TOTAL_LETTERS; ++j)
        {
            for (int k = 0; k < TOTAL_LETTERS; ++k)
            {
                for (int l = 0; l < TOTAL_LETTERS; ++l)
                {
                    for (int m = 0; m < TOTAL_LETTERS; ++m)
                    {
                        str[0] = LETTERS[i];
                        str[1] = LETTERS[j];
                        str[2] = LETTERS[k];
                        str[3] = LETTERS[l];
                        str[4] = LETTERS[m];
                        if (strcmp(crypt(str, salt), hash) == 0)
                        {
                            // printf("%s\n", str);
                            return true;
                        }                           
                    }
                }
            }
        }
    }
    return false;
}
