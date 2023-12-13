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
 * @stk: Stack
 * @l: Line number
 * Return: void
 */
void swap(stack_t **stk, unsigned int l)
{
	stack_t *n1, *n2;

	if (*stk == NULL || (*stk)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
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
 * @opcode: Opcode
 * @head: pointer to TOS
 * @ln: Line number
 * Return: void
 */

void execute_op(stack_t **head, char *opcode, unsigned int ln)
{
	if (strcmp(opcode, "pall") == 0)
		print_all(*head);
	else if (strcmp(opcode, "pint") == 0)
		pint(*head, ln);
	else if (strcmp(opcode, "pop") == 0)
		pop(head, ln);
	else if (strcmp(opcode, "sub") == 0)
		sub(head, ln);
	else if (strcmp(opcode, "div") == 0)
		stack_div(head, ln);
	else if (strcmp(opcode, "mul") == 0)
		mul(head, ln);
	else if (strcmp(opcode, "mod") == 0)
		mod(head, ln);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(head, ln);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(head);
	else if (strcmp(opcode, "add") == 0)
		add(head, ln);
	else if (strcmp(opcode, "nop") == 0)
		nop();
	else if (strcmp(opcode, "swap") == 0)
		swap(head, ln);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(head);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(head);
	else if (strcmp(opcode, "queue") == 0)
		queue(head);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
