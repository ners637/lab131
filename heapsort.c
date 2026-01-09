#include "heapsort.h"

static int deque_find_max(deque_t *deque) {
    node_t *cur = deque->front;
    int max = cur->value;

    while (cur) {
        if (cur->value > max)
            max = cur->value;
        cur = cur->next;
    }
    return max;
}

static void deque_remove_value(deque_t *deque, int value) {
    node_t *cur = deque->front;

    while (cur) {
        if (cur->value == value) {
            if (cur->prev)
                cur->prev->next = cur->next;
            else
                deque->front = cur->next;

            if (cur->next)
                cur->next->prev = cur->prev;
            else
                deque->back = cur->prev;

            free(cur);
            return;
        }
        cur = cur->next;
    }
}


void heap_sort(deque_t *deque){
    if (!deque->front || !deque->front->next) {
        return;
    }

    deque_t sorted;
    deque_init(&sorted);

    while (deque->front) {
        int max = deque_find_max(deque);
        deque_remove_value(deque, max);
        deque_push_front(&sorted, max);
    }

    while (sorted.front) {
        int val;
        deque_pop_front(&sorted, &val);
        deque_push_back(deque, val);
    }
}
