#include "deque.h"

void deque_init(deque_t *deque){
    deque->front = NULL;
    deque->back = NULL;
}

int deque_push_front(deque_t *deque, int value){
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL){
        printf("Ошибка выделения памяти\n");
        return 0;
    }

    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = deque->front;

    if (deque->front != NULL){
        deque->front->prev = new_node;
    } else {
        deque->back = new_node;
    }

    deque->front = new_node;
    return 1;
}

int deque_push_back(deque_t *deque, int value){
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL){
        printf("Ошибка выделения памяти\n");
        return 0;
    }

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = deque->back;

    if (deque->back != NULL){
        deque->back->next = new_node;
    } else {
        deque->front = new_node;
    }

    deque->back = new_node;
    return 1;
}

int deque_pop_front(deque_t *deque, int *value){
    if (deque->front == NULL){
        return 0;
    }

    node_t *current = deque->front;
    if (value != NULL){
        *value = current->value;
    }

    deque->front = current->next;
    if (deque->front != NULL){
        deque->front->prev = NULL;
    } else {
        deque->back = NULL;
    }

    free(current);
    return 1;
}

int deque_pop_back(deque_t *deque, int *value){
    if (deque->back == NULL){
        return 0;
    }

    node_t *current = deque->back;
    if (value != NULL){
        *value = current->value;
    }

    deque->back = current->prev;
    if (deque->back != NULL){
        deque->back->next = NULL;
    } else {
        deque->front = NULL;
    }

    free(current);
    return 1;
}

int deque_add_by_index(deque_t *deque, int index, int value){
    if (index < 0){
        return 0;
    }

    if (index == 0){
        return deque_push_front(deque, value);
    }

    node_t *current = deque->front;
    int current_index = 0;

    while (current != NULL && current_index < index){
        current = current->next;
        current_index++;
    }

    if (current == NULL){
        return deque_push_back(deque, value);
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL){
        printf("Ошибка выделения памяти\n");
        return 0;
    }

    new_node->value = value;
    new_node->next = current;
    new_node->prev = current->prev;

    current->prev->next = new_node;
    current->prev = new_node;

    return 1;
}

void free_deque(deque_t *deque){
    int tmp;
    while (deque->front != NULL){
        deque_pop_front(deque, &tmp);
    }
}

void write_to(deque_t* deque, char* fname) {
    FILE* file = fopen(fname, "w");  
    if (!file) {
        printf("Файл накрылся медным тазом");
        return;
    }
    
    node_t* current = deque->front;
    while (current) {
        fprintf(file, "%d ", current->value);
        current = current->next;
    }
    
    fclose(file);
}

void read_from(char* fname, deque_t* deque) {
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
