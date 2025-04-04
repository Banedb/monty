#include "monty.h"

/**
 * push_top - Adds a new node at the beginning
 * @head: top of stack
 * @n: num to be added
 *
 */

void push_top(stack_t **head, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = *head;
	if (*head)
		(*head)->prev = node;
	*head = node;
}

/**
 * push_bottom - Adds a new node at the end
 * @head: top of stack
 * @n: num to be added
 *
 */

void push_bottom(stack_t **head, const int n)
{
	stack_t *node = malloc(sizeof(stack_t)), *end = *head;

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return;
	}

	while (end->next)
		end = end->next;
	node->prev = end;
	end->next = node;
}
