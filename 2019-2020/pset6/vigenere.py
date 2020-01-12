# ------------------------------------------------------------------------------
# vigenere.py
#
# Computer Science 50
# Problem Set 6
#
# Encrypts messages using Vigenère’s cipher
#
# 2019:
# https://docs.cs50.net/2019/x/psets/6/sentimental/vigenere/vigenere.html
# ------------------------------------------------------------------------------

from sys import argv, exit


def main():
    if len(argv) != 2 or not argv[1].isalpha():
        print("Usage: python vigenere.py k")
        exit(1)

    s = input("plaintext:  ")
    print("ciphertext: {0}".format(vigenere_encrypt(s, argv[1])))


def caesar_symbol_encrypt(sym, shift):
    if 'a' <= sym <= 'z':
        sym = chr(ord('a') + (ord(sym) + shift - ord('a')) % 26)
    elif 'A' <= sym <= 'Z':
        sym = chr(ord('A') + (ord(sym) + shift - ord('A')) % 26)

    return sym


def vigenere_encrypt(str, keyword):
    keyword = keyword.lower()
    tmp_list = []
    k = 0
    kyeword_len = len(keyword)
    ord_a = ord('a')
    for c in str:
        if not c.isalpha():
            tmp_list.append(c)
            continue
        key_symbol = keyword[k % kyeword_len]
        tmp_list.append(caesar_symbol_encrypt(c, ord(key_symbol) - ord_a))
        k += 1
    return ''.join(tmp_list)


if __name__ == "__main__":
    main()
