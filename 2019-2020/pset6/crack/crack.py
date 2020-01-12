# ----------------------------------------------------------------------------
# crack.py
#
# Computer Science 50
# Problem Set 6
#
# Implement a program that cracks passwords
#
# 2019:
# https://docs.cs50.net/2019/x/psets/6/sentimental/crack/crack.html
# ----------------------------------------------------------------------------

import sys
import crypt
import string
import itertools

ALLOWED_SYMBOLS = string.ascii_lowercase + string.ascii_uppercase
WORD_SIZE = 5


def get_word_transformations(word):
    return [word, word[0].upper() + word[1:], word.upper()]


def crack_with_dict(hashword, dict_file):
    salt = hashword[:2]
    with open(dict_file, 'r') as fin:
        for line in fin:
            for word in get_word_transformations(line.rstrip()):
                if crypt.crypt(word, salt) == hashword:
                    return word


def crack(
        hashword,
        dicts=[],
        max_len=5,
        allowed_symbols=string.ascii_lowercase + string.ascii_uppercase):

    salt = hashword[:2]

    for d in dicts:
        result = crack_with_dict(hashword, d)
        if result:
            return result

    for k in range(1, max_len + 1):
        product_base = []
        for i in range(k):
            product_base.append(allowed_symbols)
        for symset in itertools.product(*product_base):
            word = ''.join(symset)
            # print(word)
            if crypt.crypt(word, salt) == hashword:
                return word


if len(sys.argv) != 2:
    print("Usage: python crack.py hash")
    exit(1)

hashword = sys.argv[1]

dicts = (
    'dicts/words_len3.txt',
    'dicts/words_len4.txt',
    'dicts/words_len5.txt',
    # 'dicts/names.txt',
)

print(crack(hashword, dicts, WORD_SIZE, ALLOWED_SYMBOLS))
