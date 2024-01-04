import sys
import crypt
import string
import itertools

ALLOWED_SYMBOLS =  string.ascii_lowercase + string.ascii_uppercase
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
    dicts = [],
    max_len = 5,
    allowed_symbols = string.ascii_lowercase + string.ascii_uppercase):

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


dicts = (
    'dicts/words_len3.txt',
    'dicts/words_len4.txt',
    'dicts/words_len5.txt',
    # 'dicts/names.txt',
)

test_list = [
    'brian:51.xJagtPnb6s',
    'bjbrown:50GApilQSG3E2',
    'emc:502sDZxA/ybHs',
    'greg:50C6B0oz0HWzo',
    'jana:50WUNAFdX/yjA',
    'lloyd:50n0AAUD.pL8g',
    'malan:50CcfIk1QrPr6',
    'natmelo:50JIIyhDORqMU',
    'rob:51v3Nh6ZWGHOQ',
    'veronica:61v1CDwwP95bY',
    'walker:508ny6Rw0aRio',
    'zamyla:50cI2vYkF0YU2'
]

for el in test_list:
    login = el[:el.index(':')]
    hashword = el[el.index(':') + 1:]
    result = crack(hashword, dicts, WORD_SIZE, ALLOWED_SYMBOLS)
    # print(login, end=' : ')
    print(login, result)
    # print(result)

# print(crack(hashword, dicts, WORD_SIZE, ALLOWED_SYMBOLS))