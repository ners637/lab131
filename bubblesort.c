#include "bubblesort.h"

void bubble_sort(deque_t *deque) {
    if (deque->front == NULL || deque->front->next == NULL)
        return;

    int swapped;
    do {
        swapped = 0;
        node_t *current = deque->front;

        while (current->next != NULL) {
            if (current->value > current->next->value) {
                int tmp = current->value;
                current->value = current->next->value;
                current->next->value = tmp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}
