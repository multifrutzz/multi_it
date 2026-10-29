#include <stdio.h>
#include "array_io.h"
#include "array_process.h"

int main(void)
{
    const int size = 20;
    double m[21];

    printf("Введите 20 элементов массива M:\n");
    if (!inputArray(m, size)) {
        printf("Ошибка ввода элементов массива.\n");
        return 1;
    }

    printf("Исходный массив:\n");
    outputArray(m, size);

    insertZeroInMiddle(m, size);

    printf("Массив после вставки нуля:\n");
    outputArray(m, size + 1);
    return 0;
}