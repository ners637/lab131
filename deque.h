#include <stdlib.h>
#include <stdio.h>


typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct deque {
    node_t *front;
    node_t *back;
} deque_t;

void deque_init(deque_t *deque);

int deque_push_front(deque_t *deque, int value);
int deque_push_back(deque_t *deque, int value);

int deque_pop_front(deque_t *deque, int *value);
int deque_pop_back(deque_t *deque, int *value);

void free_deque(deque_t *deque);

void write_to(deque_t* list, char* fname);
void read_from(char* fname, deque_t* list);
void print_deque(deque_t *deque);