#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void add(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n += (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	free(current);
}

/**
 * nop - doesn't do anything
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void nop(stack_t **top, unsigned int ln)
{
	(void)top;
	(void)ln;
}

/**
 * sub - subtracts value at TOS from value at TOS->next
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void sub(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n -= (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	free(current);
}

/**
 * _div - divides value at TOS->next by value at TOS
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void _div(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n /= (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	free(current);
}

/**
 * _mul - multiplies value at TOS->next with value at TOS
 * @top: top of the stack (TOS)
 * @ln: line number of instruction
 *
 */
void _mul(stack_t **top, unsigned int ln)
{
	stack_t *current = *top;

	if (!*top || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n *= (*top)->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	free(current);
}
