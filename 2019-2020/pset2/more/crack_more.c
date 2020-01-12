// // "More comfortable" task
// https://lab.cs50.io/cs50/labs/2019/x/crack/

// This version is more perfect and sophisticated then one accepted by CS50 - 
// https://github.com/submit50/paalso/commit/fc6c52a2da16b53860dcfbb68b703404ea9f3c76?diff=unified
// It uses dictionaries of three-, four and five-letters words in whis search by actual words goes on


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
const char *DICTS[] = {"words_len3.dat", "words_len4.dat", "words_len5.dat"};

void word_to_upper(char str[]);
_Bool check_dict(char str[], const char *filename, const char *hash, const char *salt);
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


    for (int i = 0; i < TOTAL_DICTS; ++i)
    {
        char word[i + 4];
        if (check_dict(word, DICTS[i], hash, salt))
        {
            printf("%s\n", word);
            return 0;           
        }
    }

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

void word_to_upper(char str[])
{
    int i = 0;
    char c;
    while((c = str[i]) != '\0')
    {
        str[i] = toupper(c);
        i += 1;
    }
}


// if (check_dict(word, DICTS[i], hash, salt))
_Bool check_dict(char str[], const char *filename, const char *hash, const char *salt) 
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", filename);
        return 2;
    }

    while(! feof(f))
    {
        fscanf(f, "%s", str);

        if (strcmp(crypt(str, salt), hash) == 0)
        {
            fclose(f);
            return true;            
        }

        word_to_upper(str);
        if (strcmp(crypt(str, salt), hash) == 0)
        {
            fclose(f);
            return true;            
        }

    }

    fclose(f);
    return false;
}

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