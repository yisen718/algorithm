#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


bool stack_is_empty(Stack* s)
{
    return s->head == NULL;
}

bool push_to_stack(Stack* s, int value)
{
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    if (node == NULL)
    {
        printf("malloc for push_to_stack function failed");
        return false;
    }
    node->value = value;
    node->next = s->head;
    s->head = node;
    return true;
}

int pop_from_stack(Stack* s)
{
    if (!stack_is_empty(s))
    {
        Node* p = s->head;
        int out = p->value;
        s->head = p->next;
        free(p);
        return out;
    }
    // TODO: code completetion
    exit(-1);
    return 0;
}
