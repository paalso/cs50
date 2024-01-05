/**
 * half.c
 *
 * CS50 Practice Problems 2: Half
 * 
 * Calculate your half of a restaurant bill
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float amount_with_tax = bill * (1 + tax / 100.0);
    float full_amount = amount_with_tax * (1 + tip / 100.0);
    return full_amount / 2.0;
}
