/**
 * hello.c
 *
 * Computer Science 50
 * Problem Set 1
 *
 * Prints out a simple greeting to the user
 *
 * 2019:
 * https://lab.cs50.io/cs50/labs/2019/x/hello/
 * 2020:
 * https://lab.cs50.io/cs50/labs/2020/x/hello/
 *
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("What is your name? ");
    printf("hello, %s!\n", s);
    return 0;
}
