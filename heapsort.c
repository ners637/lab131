#include <stdlib.h>
#include <stdio.h>
#include "heapsort.h"


void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}

void heap_sort(deque_t *deque){
    if (deque->front == NULL){
        return;
    }

    int capacity = 8;
    int count = 0;
    int *arr = malloc(capacity * sizeof(int));
    if (arr == NULL){
        printf("Ошибка выделения памяти\n");
        return;
    }

    while (deque->front != NULL){
        if (count >= capacity){
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL){
                printf("Ошибка выделения памяти\n");
                return;
            }
        }
        deque_pop_front(deque, &arr[count]);
        count++;
    }

    for (int i = count / 2 - 1; i >= 0; i--){
        heapify(arr, count, i);
    }

    for (int i = count - 1; i > 0; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }

    for (int i = 0; i < count; i++){
        deque_push_back(deque, arr[i]);
    }

    free(arr);
}
