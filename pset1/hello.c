/**
 * hello.c
 *
 * CS50 Problem Set 1: Hello, It’s Me
 *
 * Prints out a simple greeting to the user
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s!\n", name);
    return 0;
}
