#include "monty.h"

/**
 * free_stack - free dynamically allocated memory in stack
 * @head: top of stack
 *
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
