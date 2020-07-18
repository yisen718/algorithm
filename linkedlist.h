#pragma once

typedef struct LinkedList
{
    struct LinkedList* prev;
    int value;
    struct LinkedList* next;
}LinkedList;

LinkedList* insert_into_linkedlist(LinkedList* head, int value);



void print_linkedlist(LinkedList* head);