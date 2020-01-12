/**
 * credit.c
 *
 * Computer Science 50
 * Problem Set 1
 * "More comfortable" task
 *
 * Determines whether a provided credit card number is valid
 * according to Luhn’s algorithm.
 *
 * 2019:
 * https://lab.cs50.io/cs50/labs/2019/x/credit/
 * 2020:
 * https://lab.cs50.io/cs50/labs/2020/x/credit/
 *
 */
s
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <cs50.h>

#define AMEX_CARD    "AMEX"
#define MASTER_CARD  "MASTERCARD"
#define VISA_CARD    "VISA"
#define INVALID      "INVALID"    

short countDigits(long long number);
long long firstDigitsNumber(long long number, short digits);
short countCardControlSum(long long number);
_Bool checkCardControlSum(long long number);
short identifyCardFormat(long long number);

// ---------------------- MAIN ----------------------

int main(void)
{
    long long number;

    // char[] {}
 
    do 
    {
        number = get_long("Number: ");    
    }
    while (number <= 0);

//    checkCardControlSum(number) ? printf("TRUE\n") : printf("FALSE\n");
//    printf("Digits: %d\n", countDigits(number));
//    printf("Checksum: %d\n", countCardControlSum(number));

    switch (identifyCardFormat(number))
    {
        case 1:
            printf("%s\n", AMEX_CARD);
            break;
        case 2:
            printf("%s\n", MASTER_CARD);
            break;
        case 3:
            printf("%s\n", VISA_CARD);
            break;
        default:
            printf("%s\n", INVALID);
    }

    return 0;
}

// ---------------------- FUNCTIONS ----------------------

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

// --------------------------

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

// --------------------------

long long firstDigitsNumber(long long number, short digits) 
{
    return number / pow(10, countDigits(number) - digits);
}

// --------------------------

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
        return 0;   // invalid
    }

    if ((countDigits(number) == 15) && ((firstDigitsNumber(number, 2) == 34) || (firstDigitsNumber(number, 2) == 37))) 
    {
        return 1;   // American Express
    }

    if ((countDigits(number) == 16) && ((firstDigitsNumber(number, 2) >= 51) && (firstDigitsNumber(number, 2) <= 55))) 
    {
        return 2;   // Master Card
    }

    if ((countDigits(number) == 16) && (firstDigitsNumber(number, 1) == 4)) 
    {
        return 3;   // Visa
    }

    return 0;
}
