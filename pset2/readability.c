/**
 * readability.c
 *
 * CS50 Problem Set 2: Readability
 *
 * Calculates the approximate level of text complexity based on the Coleman-Liau index.
 */

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

typedef struct
{
    int letters;
    int words;
    int sentences;
} TextInfo;

TextInfo analyzeText(string);
bool isSentenceBoundary(char);
bool isWordBoundary(char);
int getColemanLiauIndex(TextInfo);
char *getGradeInfo(int);
void printTextInfo(TextInfo); // for debugging

int main(int argc, char *argv[])
{
    string input = get_string("Text: ");
    TextInfo textInfo = analyzeText(input);
    printTextInfo(textInfo);

    int grade = getColemanLiauIndex(textInfo);
    printf("%s\n", getGradeInfo(grade));

    return 0;
}

TextInfo analyzeText(string s)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    bool insideSentence = false;
    bool insideWord = false;
    int i = 0;
    char c;

    while ((c = s[i++]) != '\0')
    {
        if (isalpha(tolower(c)))
        {
            letters += 1;

            if (!insideWord)
            {
                words += 1;
                insideWord = true;
            }

            if (!insideSentence)
            {
                sentences += 1;
                insideSentence = true;
            }
        }
        else
        {
            if (isWordBoundary(c))
                insideWord = false;
            if (isSentenceBoundary(c))
                insideSentence = false;
        }
    }
    return (TextInfo){letters, words, sentences};
}

bool isSentenceBoundary(char c)
{
    const char SENTENCE_BOUNDARIES[] = {'.', '?', '!'};
    const int SENTENCE_BOUNDARIES_LEN = 3;

    for (int i = 0, len = sizeof(SENTENCE_BOUNDARIES) / sizeof(SENTENCE_BOUNDARIES[0]); i < len; ++i)
    {
        if (c == SENTENCE_BOUNDARIES[i])
            return true;
    }
    return false;
}

bool isWordBoundary(char c)
{
    const char WORD_BOUNDARIES[] = {' ', '\t', '\n'};

    for (int i = 0, len = sizeof(WORD_BOUNDARIES) / sizeof(WORD_BOUNDARIES[0]); i < len; ++i)
    {
        if (c == WORD_BOUNDARIES[i])
            return true;
    }
    return false;
}

int getColemanLiauIndex(TextInfo textInfo)
{
    double L = 100.0 * textInfo.letters / textInfo.words;
    double S = 100.0 * textInfo.sentences / textInfo.words;
    return (int) round(0.0588 * L - 0.296 * S - 15.8);
}

char *getGradeInfo(int grade)
{
    if (grade < 1)
        return "Before Grade 1";
    else if (grade > 16)
        return "Grade 16+";
    else
    {
        static char gradeInfo[9];
        snprintf(gradeInfo, sizeof(gradeInfo), "Grade %d", grade);
        return gradeInfo;
    }
}

// For debugging
void printTextInfo(TextInfo textInfo)
{
    printf("%d letter(s)\n", textInfo.letters);
    printf("%d word(s)\n", textInfo.words);
    printf("%d sentences(s)\n", textInfo.sentences);
}
