/**
 * scrabble.c
 *
 * CS50 Problem Set 2: Scrabble
 *
 * Calculates the Scrabble scores of two words entered by two players and
 * compares their scores based on Scrabble letter values
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int LETTER_SCORES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int lower(char);
int charId(char);
int letterScore(char, int *);
int wordScore(string, int *);

int main()
{
    string word1 = get_string("Player 1:  ");
    string word2 = get_string("Player 2:  ");

    int word1Score = wordScore(word1, LETTER_SCORES);
    int word2Score = wordScore(word2, LETTER_SCORES);

    if (word1Score > word2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (word1Score < word2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int lower(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        return 'a' + c - 'A';
    }
    return c;
}

int charId(char c)
{
    return c - 'a';
}

int letterScore(char c, int *letterScores)
{
    char loweredChar = lower(c);
    if ('a' <= loweredChar && loweredChar <= 'z')
    {
        return letterScores[charId(loweredChar)];
    }
    return 0;
}

int wordScore(string word, int *letterScores)
{
    int score = 0;
    char *c = word;
    while (*c != '\0')
    {
        score += letterScore(*c++, letterScores);
    }
    return score;
}
