# Практическая работа №1; Вариант 6

## Поэтапная сборка программы 1

Переменная CC содержит путь к GNU GCC.
Использован GNU GCC 16.2.0, macOS ARM64.

```sh
mkdir -p build/stages
"$CC" -std=c11 -E program1.c -o build/stages/program1.i
"$CC" -std=c11 -S -O0 build/stages/program1.i -o build/stages/program1.s
"$CC" -c build/stages/program1.s -o build/stages/program1.o
"$CC" build/stages/program1.o -o build/program1_staged
./build/program1_staged
```

Результаты этапов:
- program1.i - обработанный текст на C.
- program1.s — ассемблерный текст.
- program1.o — объектный файл Mach-O ARM64.
- program1_staged — исполняемый файл Mach-O ARM64.

Проверка: A = -5, B = 17.
Ожидаемая сумма: 4 + 8 + 12 + 16 = 40.
Полученная сумма: 40.

## Оптимизация программы 1

Получение ассемблерного кода:

```sh
mkdir -p build/optimization
"$CC" -std=c11 -S -O0 program1.c -o build/optimization/program1_O0.s
"$CC" -std=c11 -S -O1 program1.c -o build/optimization/program1_O1.s
"$CC" -std=c11 -S -O2 program1.c -o build/optimization/program1_O2.s
"$CC" -std=c11 -S -O3 program1.c -o build/optimization/program1_O3.s
```

Сравнение:

```sh
diff -u build/optimization/program1_O0.s build/optimization/program1_O1.s
diff -u build/optimization/program1_O1.s build/optimization/program1_O2.s
diff -u build/optimization/program1_O2.s build/optimization/program1_O3.s
```

Создание исполняемых файлов:

```sh
"$CC" -std=c11 -O0 program1.c -o build/program1_O0
"$CC" -std=c11 -O1 program1.c -o build/program1_O1
"$CC" -std=c11 -O2 program1.c -o build/program1_O2
"$CC" -std=c11 -O3 program1.c -o build/program1_O3
```

Проверка:

```sh
./build/program1_O0
./build/program1_O1
./build/program1_O2
./build/program1_O3
```

При каждом запуске введены A = -5, B = 17.
Все четыре версии вывели сумму 40.

Изменения в GNU GCC 16.2.0, ARM64:
- O1: размер стека уменьшен с 64 до 48 байт.
  Сумма и счётчик цикла хранятся в регистрах.
- O2: границы загружаются парной инструкцией ldp,
  изменено расположение переходов.
- O3: добавлен векторный цикл для двух 64 битных значений
  одновременно и отдельная обработка оставшихся значений.

Исходный код одинаковый для всех уровней.
На проверенном примере результаты совпали.
Время выполнения не измерялось.