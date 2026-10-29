#include <stdio.h>
#include <math.h>
#include "array_io.h"

int inputArray(double array[], int size)
{
    for (int i = 0; i < size; ++i) {
        if (scanf("%lf", &array[i]) != 1 || !isfinite(array[i])) {
            return 0;
        }
    }
    return 1;
}

void outputArray(const double array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%.17g", array[i]);
        if (i + 1 < size) {
            printf(" ");
        }
    }
    printf("\n");
}