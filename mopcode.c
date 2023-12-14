#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/* ========================== NOP ===================================*/
/**
 * nop - Do nothing
 * Return: void
 */
void nop(void)
{
	/* Do nothing */
}


/*=========================== ADD ====================================*/
/**
 * add - add to stack
 * @stk: Stack pointer
 * @l: Line number
 * Return: void
 */

void add(stack_t **stk, unsigned int l)
{
	stack_t *tmp;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	tmp = *stk;
	tmp->next->n += tmp->n;
	pop(stk, l);
}

/*============================= SWAP ===================================*/
/**
 * swap - swap opcode
 * @head: tos
 * @ln: Line number
 * Return: void
 */
void swap(stack_t **head, unsigned int ln)
{
	int tmp;
        if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
        tmp = (*head)->n;
        (*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}


/**
 * pint - prints value at TOS
 * @head: pointer to top of stack
 * @ln: line number
*/
void pint(stack_t *head, unsigned int ln)
{
	if (!head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * pop - removes the top element of the stack
 * @head: pointer to top of stack
 * @ln: line number
*/
void pop(stack_t **head, unsigned int ln)
{
	stack_t *temp = *head;

	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(temp);
}
