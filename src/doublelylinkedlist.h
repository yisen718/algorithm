#pragma once

typedef struct DoublelyLinkedList
{
    struct DoublelyLinkedList* prev;
    int value;
    struct DoublelyLinkedList* next;
}LinkedList;

LinkedList* insert_into_doublely_linkedlist(LinkedList* head, int value);


LinkedList* delete_from_doublely_linkedlist(LinkedList* head, int value);


LinkedList* delete_from_double_linkedlist_by_given_position(LinkedList* head, LinkedList* posi);


void print_doublely_linkedlist(LinkedList* head);
