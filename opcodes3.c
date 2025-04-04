#include "monty.h"

/**
 * _mod - calculates remainder from division of
 * value at TOS->next by value at TOS
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void _mod(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n %= (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	free(current);
}

/**
 * pchar - print value at TOS as char
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void pchar(stack_t **top, unsigned int ln)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n < 0 || (*top)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * pstr - print stack values as a string
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void pstr(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	while (current)
	{
		if (current->n < 1 || current->n > 127)
		{
			printf("\n");
			return;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotates only TOS to bottom
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void rotl(stack_t **top, unsigned int ln)
{
	stack_t *current = *top, *temp = (*top)->next;

	if (!*top || !(*top)->next)
		return;

	while (current->next)
		current = current->next;

	current->next = *top;
	(*top)->prev = current;
	(*top)->next = NULL;
	temp->prev = NULL;
	*top = temp;
	(void)ln;
}

/**
 * rotr - rotates the stack to bottom
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void rotr(stack_t **top, unsigned int ln)
{
	stack_t *current = *top, *temp, *prev = NULL;

	if (!*top || !(*top)->next)
		return;

	while (current)
	{
		temp = current->next;
		current->prev = temp;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*top = prev;
	(void)ln;
}
