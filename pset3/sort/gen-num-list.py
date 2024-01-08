#!/usr/bin/env python3

import argparse


def generate_sorted_list(filename, n):
    with open(filename, 'w') as file:
        for i in range(1, n + 1):
            file.write(f"{i}\n")


def generate_reversed_list(filename, n):
    with open(filename, 'w') as file:
        for i in range(n, 0, -1):
            file.write(f"{i}\n")


def main():
    parser = argparse.ArgumentParser(
        description='Generate text files with sequential or reversed numbers.')
    parser.add_argument('n', type=int, help='Number of lines to generate')
    parser.add_argument(
        '-r', '--reversed', action='store_true', help='Generate reversed list')

    args = parser.parse_args()

    if args.reversed:
        filename = f'reversed{args.n}.txt'
        generate_reversed_list(filename, args.n)
    else:
        filename = f'sorted{args.n}.txt'
        generate_sorted_list(filename, args.n)

    print(f"Generated {filename}")


if __name__ == "__main__":
    main()
