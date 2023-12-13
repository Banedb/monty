#include "monty.h"
/**
 * handle_opcode - implement opcodes
 * @head: pointer to top of stack
 * @opcode: ..
 * @ln: line number
 */
void handle_opcode(stack_t **head, char *opcode, unsigned int ln)
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
	else
		execute_op(head, opcode, ln);
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
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
		fprintf(stderr, "L%u: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	top->next->n /= top->n;
	pop(head, ln);
}
