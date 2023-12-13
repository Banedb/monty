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