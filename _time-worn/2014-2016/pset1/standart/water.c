// http://docs.cs50.net/problems/water/water.html
// https://cdn.cs50.net/2016/spring/psets/1/pset1/pset1.html#smart_water

#include <stdio.h>
#include <math.h>
#inclede "cs50.h"

#define WATER_SPIT 1.5 //gallons per minute
#define BOTTLE_VOL 16 //ounces
#define GALLONE_VOL 128 //ounces per gallon


int main(void)
{
    int minutes, bottles;
    do {
        printf("minutes: ");
        minutes = GetInt();
        // printf("\n");
    } while (minutes <= 0);

    bottles = (int)(WATER_SPIT * GALLONE_VOL / BOTTLE_VOL) * minutes ;
    printf("bottles: %d\n",bottles);
    return 0;
}