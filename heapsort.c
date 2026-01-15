#include "deque.h"

int deque_size(deque_t *deque) {
    int count = 0;
    node_t *curr = deque->front;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

void heap_sort(deque_t *deque) {
    if (!deque || !deque->front || !deque->front->next) return;

    deque_t sorted;
    deque_init(&sorted);

    int total = deque_size(deque);

    for (int i = 0; i < total; i++) {
        int min;
        if (deque_pop_front(deque, &min) == 0) continue;

        int n = deque_size(deque);
        deque_t temp;
        deque_init(&temp);

        for (int j = 0; j < n; j++) {
            int val;
            if (deque_pop_front(deque, &val) == 0) continue;

            if (val < min) {
                deque_push_back(&temp, min);
                min = val;
            } else {
                deque_push_back(&temp, val);
            }
        }

        deque_push_back(&sorted, min);

        int temp_size = deque_size(&temp);
        for (int j = 0; j < temp_size; j++) {
            int val;
            deque_pop_front(&temp, &val);
            deque_push_back(deque, val);
        }

        free_deque(&temp);
    }

    int sorted_size = deque_size(&sorted);
    for (int i = 0; i < sorted_size; i++) {
        int val;
        deque_pop_front(&sorted, &val);
        deque_push_back(deque, val);
    }

    free_deque(&sorted);
}
