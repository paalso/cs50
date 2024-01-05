# -----------------------------------------------------------------------------
# bleep.py
#
# Computer Science 50
# Problem Set 6
#
# Сensors messages that contain words 
# that appear on a list of supplied "banned words
#
# 2019:
# https://docs.cs50.net/2019/x/psets/6/bleep/bleep.html
# -----------------------------------------------------------------------------

from cs50 import get_string
from sys import argv, exit


def load_banned(filename):
    banned_file = open(filename, 'r')
    banned = set()
    for line in banned_file:
        banned.add(line.rstrip('\n'))
    banned_file.close()
    return banned


def main():
    if len(argv) != 2:
        print('Usage: python bleep.py dictionary')
        exit(1)

    banned = load_banned(argv[1])
    s = get_string('What message would you like to censor?\n')
    input_list = s.split(' ')
    output_list = []
    for word in input_list:
        if word.lower() in banned:
            output_list.append('*' * len(word))
        else:
            output_list.append(word)

    print(' '.join(output_list))


if __name__ == "__main__":
    main()
