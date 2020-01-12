# https://docs.cs50.net/2019/x/psets/6/sentimental/caesar/caesar.html

# Caesar cipher encription

from sys import argv, exit


def main():
    argc = len(argv)
    if argc < 2 or argc > 3:
        print("Usage: python caesar.py k")
        exit(1)

    shift = int(argv[1])
    s = input("plaintext:  ")
    print("ciphertext: {0}".format(caesar_encrypt(s, shift)))


def caesar_symbol_encrypt(sym, shift):
    if 'a' <= sym <= 'z':
        sym = chr(ord('a') + (ord(sym) + shift - ord('a')) % 26)

    if 'A' <= sym <= 'Z':
        sym = chr(ord('A') + (ord(sym) + shift - ord('A')) % 26)

    return sym


def caesar_encrypt(str, shift):
    tmp_list = []
    for c in str:
        tmp_list.append(caesar_symbol_encrypt(c, shift))

    return ''.join(tmp_list)


if __name__ == "__main__":
    main()
