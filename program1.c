#include <stdio.h>

int main(void)
{
    int a, b;
    long long sum = 0;

    printf("Введите границы A и B: ");
    if (scanf("%d%d", &a, &b) != 2) {
        printf("Ошибка ввода. Нужны два целых числа.\n");
        return 1;
    }

    if (a > b) {
        printf("Ошибка: A должно быть не больше B.\n");
        return 1;
    }

    for (long long i = a; i <= b; ++i) {
        if (i > 0 && i % 4 == 0) {
            sum += i;
        }
    }

    printf("Сумма: %lld\n", sum);
    return 0;
}