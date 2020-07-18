#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList *insert_into_linkedlist(LinkedList *head, int value)
{
    LinkedList *new_node = malloc(sizeof(LinkedList));
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

LinkedList *delete_from_linkedlist(LinkedList *head, int value)
{
    LinkedList *p = head;
    while (p != NULL && p->value != value)
    {
        p = p->next;
    }

    if (p != NULL)
    {
        // first element
        if (p->prev == NULL)
        {
            head = p->next;
        }
        else
        {
            p->prev->next = p->next;

            if (p->next != NULL)
            {
                p->next->prev = p->prev;
            }
        }
        free(p);
    }

    return head;
}

void print_linkedlist(LinkedList *head)
{
    LinkedList *p = head;
    while (p != NULL)
    {
        printf("Linkedlist element: %d\n", p->value);
        p = p->next;
    }
}
