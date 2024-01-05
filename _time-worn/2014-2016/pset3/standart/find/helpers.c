/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include "cs50.h"

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
// bool search(int value, int values[], int n)
// {
//     for (int i = 0; i < n; ++i) {
//     	if (values[i] == value)
//     		return true;
//     }
//     return false;
// }

bool search(int value, int values[], int n)
{

	int mid, low, high;
	low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        if (value > values[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (values[low] == value) {
        return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int d = n / 2 ; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            int element = values[i];
            int j = i;
            while (j >= d && values[j - d] > element) {
                values[j] = values[j - d];
                j -= d;
            }
            values[j] = element;
        }
    }
}