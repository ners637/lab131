#include "bubblesort.h"

void bubble_sort(deque_t *deque) {
    if (!deque || !deque->front || !deque->front->next) {
        return;
    }
    
    int swapped = 0;
    int n = 0;
    
    node_t *count_node = deque->front;
    while (count_node) {
        n++;
        count_node = count_node->next;
    }
    
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        
        deque_t temp_deque;
        deque_init(&temp_deque);
        
        node_t *current = deque->front;
        while (current) {
            deque_push_back(&temp_deque, current->value);
            current = current->next;
        }
        
        int clear_value;
        while (deque->front) {
            deque_pop_front(deque, &clear_value);
        }
        
        for (int j = 0; j < n - i - 1; j++) {
            int value1 = 0, value2 = 0;
            deque_pop_front(&temp_deque, &value1);
            
            if (temp_deque.front) {
                value2 = temp_deque.front->value;
                
                if (value1 > value2) {
                    swapped = 1;
                    deque_pop_front(&temp_deque, &value2); 
                    deque_push_back(deque, value2); 
                    deque_push_front(&temp_deque, value1); 
                } else {
                    deque_push_back(deque, value1); 
                }
            } else {
                deque_push_back(deque, value1); 
            }
        }
        
        
        while (temp_deque.front) {
            int value;
            deque_pop_front(&temp_deque, &value);
            deque_push_back(deque, value);
        }
        
        free_deque(&temp_deque);
        
        if (!swapped) {
            break; 
        }
    }
}