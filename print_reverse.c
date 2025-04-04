#include "monty.h"

/**
 * print_reverse - print stack in reverse
 * @top: top of stack
 *
 */
void print_reverse(stack_t *top)
{
	stack_t *current = top;

	if (!current)
		return;
	while (current->next)
		current = current->next;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
