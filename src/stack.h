#pragma once
#include<stdbool.h>


typedef struct Node
{
    int value;
    struct Node* next;
} Node;


typedef struct
{
    Node* head;
} Stack;


bool stack_is_empty(Stack* s);


bool push_to_stack(Stack* s, int value);


int pop_from_stack(Stack* s);
