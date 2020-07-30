#include <stdio.h>
#include <stdlib.h>
#include "doublelylinkedlist.h"

LinkedList* insert_into_doublely_linkedlist(LinkedList* head, int value)
{
    LinkedList* new_node = malloc(sizeof(LinkedList));
    if (new_node == NULL)
    {
        fprintf(stderr, "malloc for new_node failed");
        exit(EXIT_FAILURE);
    }
    new_node->prev = NULL;
    new_node->value = value;
    head->prev = new_node;
    new_node->next = head;
    return new_node;
}

LinkedList* delete_from_doublely_linkedlist(LinkedList* head, int value)
{
    LinkedList* p = head;
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
        }

        // last element
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        free(p);
    }

    return head;
}

LinkedList* delete_from_double_linkedlist_by_given_position(LinkedList* head, LinkedList* posi)
{
    if (posi->prev != NULL)
    {
        posi->prev->next = posi->next;
    }
    else
    {
        head = posi->next;
    }
    if (posi->next != NULL)
    {
        posi->next->prev = posi->prev;
    }
    free(posi);
    return head;
}

void print_doublely_linkedlist(LinkedList* head)
{
    LinkedList* p = head;
    while (p != NULL)
    {
        printf("Linkedlist element: %d\n", p->value);
        p = p->next;
    }
}
