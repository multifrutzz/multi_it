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

## Оптимизация (1 программа)

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

## Раздельная компиляция (2 программа)
```sh
mkdir -p build/objects
"$CC" -std=c11 -Wall -Wextra -Wpedantic -c array_io.c -o build/objects/array_io.o
"$CC" -std=c11 -Wall -Wextra -Wpedantic -c array_process.c -o build/objects/array_process.o
"$CC" -std=c11 -Wall -Wextra -Wpedantic -c program2.c -o build/objects/program2.o
"$CC" build/objects/program2.o build/objects/array_io.o build/objects/array_process.o -o build/program2
./build/program2
```

Проверки:
1. В массиве -8 5 -3 0 7 -1 2 -6 4 0 -2 9 -4 3 -5 6 -7 1
   элементы 5 и -1 поменялись местами, остальные сохранились.
2. При замене 11-го элемента исходного массива на -1
   обмен выполнен с первым вхождением -1, на 6-м месте.
3. Для массива из чисел от 1 до 18 выведено сообщение
   о невозможности обмена. Массив не изменился.

## Раздельная компиляция (3 программа)

```sh
"$CC" -std=c11 -Wall -Wextra -Wpedantic -c program3.c -o build/objects/program3.o
"$CC" build/objects/program3.o build/objects/array_io.o build/objects/array_process.o -o build/program3
./build/program3
```

Проверка:

Ввод:
```text
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```

Результат после вставки нуля:
```text
1 2 3 4 5 6 7 8 9 10 0 11 12 13 14 15 16 17 18 19 20
```

## Статическая библиотека

Создание библиотеки и просмотр её содержимого:

```sh
mkdir -p build/library
ar crs build/library/libarraywork.a build/objects/array_io.o build/objects/array_process.o
ar t build/library/libarraywork.a
```

В библиотеке находятся array_io.o и array_process.o.

Сборка программ с подключением библиотеки:

```sh
"$CC" build/objects/program2.o -Lbuild/library -larraywork -o build/program2_static
"$CC" build/objects/program3.o -Lbuild/library -larraywork -o build/program3_static
```

Проверка запуска:

```sh
./build/program2_static
./build/program3_static
```

Программа 2:
Ввод: -8 5 -3 0 7 -1 2 -6 4 0 -2 9 -4 3 -5 6 -7 1
Результат: -8 -1 -3 0 7 5 2 -6 4 0 -2 9 -4 3 -5 6 -7 1

Программа 3:
Ввод: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Результат: 1 2 3 4 5 6 7 8 9 10 0 11 12 13 14 15 16 17 18 19 20