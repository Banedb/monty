#include "monty.h"
/**
 * free_stack - frees a listint_t list
 * @head: pointer to list to be freed
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
