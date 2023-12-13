#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* stack_t *head = NULL; */

/**
 * queue - Do nothing
 * @h: Stack
 * Return: void
 */

void queue(stack_t **h)
{
	stack_t *tmp;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	tmp = *h;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->prev->next = NULL;
	tmp->next = NULL;


	/* Updating head to point to the front of the queue */
	tmp->next = *h;
	(*h)->prev = tmp;
	*h = tmp;

}

/**
 * rotr - rotl opcode
 * @stk: Stack
 * Return: void
 */
void rotr(stack_t **stk)
{
	stack_t *tmp, *curr;

	if (*stk != NULL && (*stk)->next != NULL)
	{
		return;
	}

	curr = *stk;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	tmp = curr->prev;
	tmp->next = NULL;
	curr->prev = NULL;
	curr->next = *stk;
	(*stk)->prev = curr;

	*stk = curr;
}

/**
 * exit_f - Exit for unknown opcode
 * @ln: Line no
 * @op: Opcode
 * @h: Stack
 * Return: void
 */
void exit_f(unsigned int ln, char *op, stack_t *h)
{
	fprintf(stderr, "L<%u>: unknown instruction %s\n", ln, op);
	free_stack(h);
	exit(EXIT_FAILURE);
}
