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
 * add - add opcode
 * @stk: Stack pointer
 * @l: Line number
 * Return: void
 */

void add(stack_t **stk, unsigned int l)
{
	stack_t *tmp;

	int sum = 0;

	if (!stk || !(*stk) || !(*stk)->next)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short", l);
		exit(EXIT_FAILURE);
	}

	tmp = *stk;
	tmp->next->n += tmp->n;
	pop(stk, l);
}

/*============================= SWAP ===================================*/
/**
 * swap - swap opcode
 * @stk: Stack
 * @l: Line number
 * Return: void
 */
void swap(stack_t **stk, unsigned int l)
{
	stack_t *n1, *n2;

	if (*stk == NULL || (*stk)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	n1 = *stk;
	n2 = n1->next;


	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;

	if (n2->prev != NULL)
		n2->prev->next = n2;

	if (n1->next != NULL)
		n1->next->prev = n1;

	(*stk) = n2;
}

/* ============================= ROTL ===================================*/
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

/*================================== EXECUTE OPCODE ======================= */

/**
 * execute_op - execute opcode
 * @op: Opcode
 * @stack: Stack
 * @ln: Line
 * Return: void
 */

void execute_op(stack_t **stack, const char *op, unsigned int ln)
{
	if (strcmp(op, "add") == 0)
	{
		add(stack, ln);
	}
	else if (strcmp(op, "swap") == 0)
	{
		swap(stack, ln);
	}
	else if (strcmp(op, "nop") == 0)
	{
		(void)ln;
		nop();
	}
	else if (strcmp(op, "queue") == 0)
	{
		(void)ln;
		queue(stack);
	}
	else if (strcmp(op, "rotl") == 0)
	{
		(void)ln;
		rotl(stack);
	}
	else if (strcmp(op, "rotr") == 0)
	{
		(void)ln;
		rotr(stack);
	}
}
