# Практическая работа №1; Вар №6

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