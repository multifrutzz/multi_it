#include "array_process.h"

int swapMaxNegativeAndFirstPositive(double array[], int size)
{
    int maxNegative = -1;
    int firstPositive = -1;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            if (maxNegative == -1 || array[i] > array[maxNegative]) {
                maxNegative = i;
            }
        }
        if (array[i] > 0 && firstPositive == -1) {
            firstPositive = i;
        }
    }

    if (maxNegative == -1 || firstPositive == -1) {
        return 0;
    }

    double temp = array[maxNegative];
    array[maxNegative] = array[firstPositive];
    array[firstPositive] = temp;
    return 1;
}

void insertZeroInMiddle(double array[], int size)
{
    int middle = size / 2;

    for (int i = size; i > middle; --i) {
        array[i] = array[i - 1];
    }
    array[middle] = 0;
}