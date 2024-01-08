#!/usr/bin/env python3

import subprocess
import time

PROGRAMS = ["./sort1", "./sort2", "./sort3"]
INPUT_FILES = [
    "sorted5000.txt",
    "sorted10000.txt",
    "sorted50000.txt",
    "reversed5000.txt",
    "reversed10000.txt",
    "reversed50000.txt",
    "random5000.txt",
    "random10000.txt",
    "random50000.txt",
]


def run_program(program, input_file):
    start_time = time.time()
    subprocess.run([program, input_file],
                   stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    end_time = time.time()
    duration = end_time - start_time
    return duration


def main():
    print("Duration of sorting by different algorithms in seconds")
    print("{:20} | {:>8} | {:>8} | {:>8}".format("", *PROGRAMS))
    print("-" * 60)

    for input_file in INPUT_FILES:
        durations = [run_program(program, input_file) for program in PROGRAMS]
        print("{:20} | {:>8.3f} | {:>8.3f} | {:>8.3f}"
              .format(input_file, *durations))

if __name__ == "__main__":
    main()
