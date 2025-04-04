#include "monty.h"

/**
 * push - push int s to top of stack
 * @top: top of the stack
 * @s: string of num to push
 * @ln: line number of instruction
 *
 */
void push(stack_t **top, char *s, unsigned int ln)
{
	int n;

	if (!valid_num(s))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	n = atoi(s);
	if (format)
		push_bottom(top, n);
	else
		push_top(top, n);
}

/**
 * pall - print all elements of the stack
 * @top: top of the stack
 * @ln: line number of instruction
 *
 */
void pall(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!top)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)ln;
}

/**
 * pint - print value at TOS
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void pint(stack_t **top, unsigned int ln)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
 * pop - remove value at TOS
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void pop(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	*top = (*top)->next;
	free(current);
}

/**
 * swap - swaps the top two elements of the stack
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void swap(stack_t **top, unsigned int ln)
{
	stack_t *current = (*top)->next;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next = (*top)->next->next;
	(*top)->prev = current;
	if ((*top)->next)
		(*top)->next->prev = *top;
	current->next = (*top);
	current->prev = NULL;
	*top = current;
}
