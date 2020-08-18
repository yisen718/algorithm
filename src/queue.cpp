#include <stdio.h>
#include "queue.h"

int queue_is_full(Queue* q)
{
    return q->size == QUEUE_COMPACITY;
}

int queue_is_empty(Queue* q)
{
    return q->size == 0;
}

void enqueue(Queue* q, int x)
{

    if (!queue_is_full(q))
    {

        q->values[q->tail] = x;

        if (q->tail == QUEUE_COMPACITY - 1)
        {
            // 满了后回头
            q->tail = 0;
        }
        // 加1后给下次enqueue
        q->tail += 1;
        q->size += 1;
    }
    else
    {
        // 上溢
        fprintf(stderr, "Overflow, no place to enqueue");
    }
}

int dequeue(Queue* q)
{
    int x;
    if (!queue_is_empty(q))
    {

        x = q->values[q->head];
        // 判断回头
        if (q->head == QUEUE_COMPACITY - 1)
        {
            q->head = 0;
        }
        q->head += 1;
        q->size -= 1;
        return x;
    }
    fprintf(stderr, "Underflow, no element to dequeue");
    return -1;
}
