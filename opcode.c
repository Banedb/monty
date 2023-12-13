#include "monty.h"
/**
 * mul - TOS1 x TOS, pop TOS
 * @head: stack pointer
 * @ln: line number being operated on
 */
void mul(stack_t **head, unsigned int ln)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	top = *head;
	top->next->n *= top->n;
	pop(head, ln);
}

/**
 * mod - mod of TOS1 and TOS
 * @head: stack pointer
 * @ln: line number being operated on
 */
void mod(stack_t **head, unsigned int ln)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", ln);
		exit(EXIT_FAILURE);
	}
	top->next->n %= top->n;
	pop(head, ln);
}

/**
 * pchar - prints TOS as char
 * @head: pointer to stack
 * @ln: line number
 */
void pchar(stack_t **head, unsigned int ln)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", ln);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*head)->n);
}

/**
 * pstr - print stack values as str starting from TOS
 * @head: pointer to stack
 */
void pstr(stack_t **head)
{
	stack_t *top = *head;

	for (; top; top = top->next)
	{
		if (top->n < 1 || top->n > 127)
			break;
		printf("%c", (char)top->n);
	}
	printf("\n");
}
