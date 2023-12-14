#include "monty.h"
/**
 * free_stack - frees stack
 * @head: pointer to stack
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
