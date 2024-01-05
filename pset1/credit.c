/**
 * credit.c
 *
 * CS50 Problem Set 1: Credit
 *
 * Determines whether a provided credit card number is valid
 * according to Luhn’s algorithm.
 */

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define AMEX_CARD 1
#define MASTER_CARD 2
#define VISA_CARD 3
#define INVALID 0

short countDigits(long long number);
long long getFirstNumberDigits(long long number, short digits);
short countCardControlSum(long long number);
_Bool checkCardControlSum(long long number);
short identifyCardFormat(long long number);

int main(void)
{
    long long number;

    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    switch (identifyCardFormat(number))
    {
        case AMEX_CARD:
            printf("AMEX\n");
            break;
        case MASTER_CARD:
            printf("MASTERCARD\n");
            break;
        case VISA_CARD:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
    }

    return 0;
}

short countCardControlSum(long long number)
{
    int cheksum = 0;
    int evenDoubledDigit;

    while (number > 0)
    {
        cheksum += number % 10;
        number /= 10;
        evenDoubledDigit = 2 * (number % 10);
        cheksum += evenDoubledDigit < 10 ? evenDoubledDigit : evenDoubledDigit - 9;
        number /= 10;
    }
    return cheksum;
}

_Bool checkCardControlSum(long long number)
{
    return countCardControlSum(number) % 10 == 0 ? true : false;
}

short countDigits(long long number)
{
    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }
    return count;
}

long long getFirstNumberDigits(long long number, short digits)
{
    return number / pow(10, countDigits(number) - digits);
}

short identifyCardFormat(long long number)
/*
identifies 378282246310005 as AMEX
identifies 371449635398431 as AMEX
identifies 5555555555554444 as MASTERCARD
identifies 5105105105105100 as MASTERCARD
identifies 4111111111111111 as VISA
identifies 4012888888881881 as VISA
*/
{
    if (!checkCardControlSum(number))
    {
        return INVALID;
    }

    short digitsCount = countDigits(number);
    short firstTwoDigitsNumber = getFirstNumberDigits(number, 2);

    if ((digitsCount == 15) && ((firstTwoDigitsNumber == 34) || (firstTwoDigitsNumber == 37)))
    {
        return AMEX_CARD;
    }

    if ((digitsCount == 16) && ((firstTwoDigitsNumber >= 51) && (firstTwoDigitsNumber <= 55)))
    {
        return MASTER_CARD;
    }

    short firstDigitNumber = getFirstNumberDigits(number, 1);
    if ((countDigits(number) == 16 || digitsCount == 13) && (firstDigitNumber == 4))
    {
        return VISA_CARD;
    }

    return 0;
}
