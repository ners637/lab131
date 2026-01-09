#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "deque.h"
#include "bubblesort.h"
#include "heapsort.h"

// Получение числа с проверкой ввода
int get_integer_input(char* prompt) {
    int value;
    int check = 0;
    char buffer;
    while (check != 1) {
        printf("%s", prompt);
        check = scanf("%d", &value);
        if (check == 1) {
            if (scanf("%1[^\n]", &buffer) == 1) {
                printf("Не должно быть букв\n");
                scanf("%*[^\n]");
                check = 0;
                continue;
            }
            return value;
        }
        printf("Ошибка ввода\n");
        scanf("%*[^\n]");
    }
    return 1;
}

// Считываем числа из файла в дек
void read_file_to_deque(const char* fname, deque_t* deque) {
    FILE* file = fopen(fname, "r");
    if (!file) {
        printf("Не удалось открыть файл %s\n", fname);
        return;
    }
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        deque_push_back(deque, num);
    }
    fclose(file);
}

// Сортировка и запись времени
void sort_and_time(deque_t* deque, void (*sort_func)(deque_t*), const char* sort_name) {
    clock_t start = clock();
    sort_func(deque);
    clock_t duration = clock() - start;

    printf("%s сортировка завершена. Время: %f секунд\n", sort_name, (float)duration / CLOCKS_PER_SEC);

    // Запись времени в файл
    FILE* file = fopen("time.txt", "a");
    if (file) {
        fprintf(file, "%f ", (float)duration / CLOCKS_PER_SEC);
        fclose(file);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Список файлов с тестовыми данными
    const char* test_files[] = {
        "numbers_10.txt",
        "numbers_100.txt",
        "numbers_1000.txt",
        "numbers_10000.txt",
        "numbers_100000.txt"
    };
    const int num_files = 5;

    // Очищаем старый файл с временем
    FILE* f = fopen("time.txt", "w");
    if (f) fclose(f);

    for (int i = 0; i < num_files; i++) {
        printf("\nФайл: %s\n", test_files[i]);
        deque_t deque;

        // --- Heap Sort ---
        deque_init(&deque);
        read_file_to_deque(test_files[i], &deque);
        sort_and_time(&deque, heap_sort, "Heap");
        free_deque(&deque);

        // --- Bubble Sort ---
        deque_init(&deque);
        read_file_to_deque(test_files[i], &deque);
        sort_and_time(&deque, bubble_sort, "Bubble");
        free_deque(&deque);

        // Перевод строки в time.txt после каждой пары
        f = fopen("time.txt", "a");
        if (f) {
            fprintf(f, "\n");
            fclose(f);
        }
    }

    printf("\nГотово! Файл time.txt обновлен.\n");
    return 0;
}
