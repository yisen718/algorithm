#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "stack.h"
#include "linkedlist.h"

int main ()
{
	/*LinkedList* head = malloc(sizeof(LinkedList));
	head->prev = NULL;
	head->next = NULL;
	head->value = 0;

	for (int i = 1; i < 1000; i++)
	{
		head = insert_into_linkedlist(head, i);
	}

	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0)
		{
			head = delete_from_linkedlist(head, i);
		}
	}

	print_linkedlist(head);*/
	Stack* stack = malloc(sizeof(Stack));
	stack->head = NULL;

	for (int i = 0; i < 1000; i++)
	{
		push_to_stack(stack, i);
	}

	for (int i = 0; i < 1010; i++)
	{
		printf("Pop from stack: %d\n", pop_from_stack(stack));
	}
	return 0;
}