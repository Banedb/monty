#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * print_all - prints all elements of a listint_t list
 * @h: pointer to head of list
 */
void print_all(const stack_t *h)
{
	const stack_t *current = h;

	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}

/**
 * sub - subtracts TOS from TOS1
 * @head: pointer to top of stack
 * @ln: line number
*/
void sub(stack_t **head, unsigned int ln)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	top = *head;
	top->next->n -= top->n;
	pop(head, ln);
}

/**
 * rotl - rotl opcode
 * @stk: Stack
 * Return: void
 */

void rotl(stack_t **stk)
{
	stack_t *tmp, *last;

	if (*stk != NULL && (*stk)->next != NULL)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		last = *stk;

		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		(*stk)->prev = NULL;
	}
}


/**
 * rotr - rotl opcode
 * @head: Stack
 * Return: void
 */
void rotr(stack_t **head)
{
	stack_t *first, *temp = *head;

	if (!head || !(*head) || !(*head)->next)
		return;
	while (temp->next->next)
		temp = temp->next;
	first = temp->next;
	temp->next = NULL;
	first->next = *head;
	*head = first;
}
