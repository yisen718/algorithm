#pragma once
#define QUEUE_COMPACITY 100

typedef struct Queue {
    int head;
    int tail;
    int size;
    int values[QUEUE_COMPACITY];
} Queue;

typedef struct LinkedQueue {
    int value;
    struct LinkedQueue* next;
} LinkedQueue;

int queue_is_full(Queue* q);

int queue_is_empty(Queue* q);

void enqueue(Queue* q, int x);

int dequeue(Queue* q);
