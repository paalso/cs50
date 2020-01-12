# ------------------------------------------------------------------------------
# readability.py
#
# Computer Science 50
# Problem Set 6
#
# Implement a program that computes the approximate grade level needed
# to comprehend some text
#
# 2020:
# https://cs50.harvard.edu/x/2020/psets/6/readability
# ------------------------------------------------------------------------------

import cs50
import re


def get_Coleman_Liau_index(letters, words, sentences):
    L = 100 * letters / words
    S = 100 * sentences / words
    return round(0.0588 * L - 0.296 * S - 15.8)


def main():
    text = cs50.get_string('Text: ')
    # text = input('Text: ')
    letters = len(list(filter(lambda c: c.lower().isalpha(), text)))
    words = len(text.split())
    sentences = len(re.findall(r'[.?!]', text))
    grade = get_Coleman_Liau_index(letters, words, sentences)

    if grade < 1:
        print('Before Grade 1')
    elif grade > 16:
        print('Grade 16+')
    else:
        print(f'Grade {grade}')


if __name__ == '__main__':
    main()
