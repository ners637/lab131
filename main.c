#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "deque.h"
#include "bubblesort.h"
#include "heapsort.h"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Russian");

    deque_t deque;
    deque_init(&deque);

    void (*sort_func)(deque_t *) = heap_sort;

    for (int i = 1; i < argc; i++) {

        if (!strcmp(argv[i], "--heap")) {
            sort_func = heap_sort;
        }
        else if (!strcmp(argv[i], "--bubble")) {
            sort_func = bubble_sort;
        }

        else if (!strcmp(argv[i], "--10")) {
            read_from("numbers_1000.txt", &deque);
        }
        else if (!strcmp(argv[i], "--100")) {
            read_from("numbers_6500.txt", &deque);
        }
        else if (!strcmp(argv[i], "--1000")) {
            read_from("numbers_10000.txt", &deque);
        }
        else if (!strcmp(argv[i], "--10000")) {
            read_from("numbers_50000.txt", &deque);
        }
        else if (!strcmp(argv[i], "--100000")) {
            read_from("numbers_100000.txt", &deque);
        }

        else if (!strcmp(argv[i], "--file")) {
            printf("Исходный ряд:\n");
            read_from("stalin.txt", &deque);
            free_deque(&deque);

            printf("Отсортированный ряд:\n");
            read_from("sorted.txt", &deque);
            free_deque(&deque);
            return 0;
        }
    }

    if (deque.front == NULL) {
        printf("Нет данных для сортировки\n");
        return 1;
    }

    write_to(&deque, "stalin.txt");

    clock_t start = clock();
    sort_func(&deque);
    clock_t duration = clock() - start;

    write_to(&deque, "sorted.txt");

    FILE *file = fopen("time.txt", "a");
    if (file) {
        fprintf(file, "%f\n", (float)duration / CLOCKS_PER_SEC);
        fclose(file);
    }

    free_deque(&deque);
    return 0;
}
