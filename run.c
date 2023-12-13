#include "monty.h"
/**
 * run_opcode - implement opcodes
 * @head: pointer to top of stack
 * @opcode: ..
 * @ln: line number
 */
void run_opcode(stack_t **head, char *opcode, unsigned int ln)
{
	int value;
	char *str_val = NULL, *delim = " \n\t\r";

	if (strcmp(opcode, "push") == 0)
	{
		str_val = strtok(NULL, delim);
		if (valid_num(str_val) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", ln);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		value = atoi(str_val);
		push(value, head);
	}
	else if (strcmp(opcode, "pall") == 0)
		print_all(*head);
	else if (strcmp(opcode, "pint") == 0)
		pint(*head, ln);
	else if (strcmp(opcode, "pop") == 0)
		pop(head, ln);
	else if (strcmp(opcode, "sub") == 0)
		sub(head, ln);
	else if (strcmp(opcode, "div") == 0)
		stack_div(head, ln);
	else
	{
		fprintf(stderr,	"L%u: unknown instruction %s\n", ln, opcode);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pint - prints value of TOS
 * @head: pointer to top of stack
 * @ln: line number
*/
void pint(stack_t *head, unsigned int ln)
{
	if (!head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", ln);
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
		fprintf(stderr, "L%u: can't pop an empty stack", ln);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	free(temp);
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
		fprintf(stderr, "L%u: can't sub, stack too short", ln);
		exit(EXIT_FAILURE);
	}

	top = *head;
	top->next->n -= top->n;
	pop(head, ln);
}

/**
 * stack_div - divides TOS1 by TOS
 * @head: pointer to top of stack
 * @ln: line number
*/

void stack_div(stack_t **head, unsigned int ln)
{
	stack_t *top;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", ln);
		exit(EXIT_FAILURE);
	}
	top->next->n /= top->n;
	pop(head, ln);
}
