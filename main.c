#include <stdio.h>
#include <stdlib.h>
#include"fun.h"
#include "linkedlist.h"

int main ()
{
	LinkedList* head = malloc(sizeof(LinkedList));
	head->prev = NULL;
	head->next = NULL;
	head->value = 0;

	for (int i = 1; i < 1000; i++)
	{
		head = insert_into_linkedlist(head, i);
	}

	print_linkedlist(head);
	
	return 0;
}