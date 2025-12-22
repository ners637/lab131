#include "bubblesort.h"

void bubble_sort(deque_t *deque){
    if (deque->front == NULL){
        return;
    }

    int swapped;

    do {
        swapped = 0;

        int first;
        int second;

        /* забираем первый элемент */
        deque_pop_front(deque, &first);

        while (deque->front != NULL){
            deque_pop_front(deque, &second);

            if (first > second){
                deque_push_back(deque, second);
                swapped = 1;
            } else {
                deque_push_back(deque, first);
                first = second;
            }
        }

        /* возвращаем последний элемент */
        deque_push_back(deque, first);

    } while (swapped);
}
