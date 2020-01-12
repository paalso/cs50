/**
 * readability.c
 *
 * Computer Science 50
 * Problem Set 2
 *
 * Computes the approximate grade level needed to comprehend some text
 *
 * 2020:
 * https://cs50.harvard.edu/x/2020/psets/2/readability/
 *
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>

struct text_info
{
    int letters;
    int words;
    int sentences;
};

// Prototypes
struct text_info analyze_text(string);
bool is_sentence_boundary(char);
bool is_word_boundary(char);
int get_Coleman_Liau_index(struct text_info);

// MAIN
int main(int argc, char *argv[])
{
    struct text_info text_data;
    string input = get_string("Text: ");
    text_data = analyze_text(input);
    int grade = get_Coleman_Liau_index(text_data);

    // printf("%d letter(s)\n", text_data.letters);
    // printf("%d word(s)\n", text_data.words);
    // printf("%d sentences(s)\n", text_data.sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return 0;
}


// Functions
struct text_info analyze_text(string s)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    char c;
    int i = 0;
    bool is_in_sentence = false;
    while ((c = s[i++]) != '\0')
    {
        if (isalpha(tolower(c)))
        {
            letters += 1;
        }
        else if (is_sentence_boundary(c))
        {
            sentences += 1;
        }

        if (! is_word_boundary(c) && ! is_in_sentence)
        {
            words += 1;
            is_in_sentence = true;
        }
        else if (is_word_boundary(c))
        {
            is_in_sentence = false;
        }
    }
    return (struct text_info)
    {
        letters, words, sentences
    };
}


bool is_sentence_boundary(char c)
{
    const char SENTENCE_BOUNDARIES[] = {'.', '?', '!'};
    const int SENTENCE_BOUNDARIES_LEN = 3;

    for (int i = 0; i < SENTENCE_BOUNDARIES_LEN; ++i)
    {
        if (c == SENTENCE_BOUNDARIES[i])
        {
            return true;
        }
    }
    return false;
}


bool is_word_boundary(char c)
{
    const char WORD_BOUNDARIES[] = {' ', '\t', '\n'};
    const int WORD_BOUNDARIES_LEN = 3;

    for (int i = 0; i < WORD_BOUNDARIES_LEN; ++i)
    {
        if (c == WORD_BOUNDARIES[i])
        {
            return true;
        }
    }
    return false;
}


int get_Coleman_Liau_index(struct text_info text_data)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text,
    // S is the average number of sentences per 100 words in the text
    double L  = 100.0 * text_data.letters / text_data.words;
    double S  = 100.0 * text_data.sentences / text_data.words;
    return (int) round(0.0588 * L - 0.296 * S - 15.8);
}
