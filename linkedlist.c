#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

LinkedList* insert_into_linkedlist(LinkedList* head, int value)
{
    LinkedList* new_node = malloc(sizeof(LinkedList));
    if (new_node == NULL)
    {
        printf("malloc for new_node failed");
        exit(EXIT_FAILURE);
    }
    new_node->prev = NULL;
    new_node->value = value;
    head->prev = new_node;
    new_node->next = head;
    return new_node;
}

void print_linkedlist(LinkedList* head)
{
    LinkedList* p = head;
    while (p != NULL)
    {
        printf("Linkedlist element: %d\n", p->value);
        p = p->next;
    }
}
