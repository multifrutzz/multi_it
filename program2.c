#include <stdio.h>
#include "array_io.h"
#include "array_process.h"

int main(void)
{
    const int size = 18;
    double b[18];

    printf("Введите 18 элементов массива B:\n");
    if (!inputArray(b, size)) {
        printf("Ошибка ввода элементов массива.\n");
        return 1;
    }

    printf("Исходный массив:\n");
    outputArray(b, size);

    if (swapMaxNegativeAndFirstPositive(b, size)) {
        printf("Массив после обмена:\n");
    } else {
        printf("Обмен невозможен: нет отрицательного или положительного элемента.\n");
        printf("Массив не изменён:\n");
    }
    outputArray(b, size);
    return 0;
}