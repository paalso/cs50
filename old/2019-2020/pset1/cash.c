// https://lab.cs50.io/cs50/labs/2020/x/cash/
// https://lab.cs50.io/cs50/labs/2019/x/cash/

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    double amount;
    int rest;
    int coins = 0;
    int coins_nominals[4] = {25, 10, 5, 1};
    
    do
    {
        amount = get_float("Change owed: ");
    }
    while (amount < 0);

    rest = (int)(round(amount * 100));
    
    for (int i = 0; i < 4; ++i)
    {
        coins += rest / coins_nominals[i];
        rest %= coins_nominals[i];
    }

    printf("%i\n", coins);
    
    return 0;
}
