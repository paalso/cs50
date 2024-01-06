/**
 * hours.c
 *
 * CS50 Practice Problems 2: Hours
 *
 * Calculates total or average study hours per week based on user input.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

float sum(float *, int);
float average(float *, int);

int main(void)
{
    int numberOfWeeks = get_int("Number of weeks taking CS50: ");
    float *hours = malloc(numberOfWeeks * sizeof(int));

    for (int i = 0; i < numberOfWeeks; i++)
    {
        printf("Week %d HW Hours: ", i + 1);
        scanf("%f", &hours[i]);
    }

    char operation;
    do
    {
        operation = get_char("Enter T for total hours, A for average hours per week: ");
    }
    while (operation != 'T' && operation != 'A');

    float result = operation == 'T' ? sum(hours, numberOfWeeks) : average(hours, numberOfWeeks);
    printf("%.1f hours", result);

    return 0;
}

float sum(float *array, int size)
{
    float sum_ = 0;
    for (int i = 0; i < size; i++)
        sum_ += array[i];
    return sum_;
}

float average(float *array, int size)
{
    return sum(array, size) / size;
}
