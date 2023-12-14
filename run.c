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

	if (strcmp(opcode, "stack") == 0)
	{
		format = 0;
		return;
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		format = 1;
		return;
	}
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
		if (format)
			enqueue(value, head);
		else
			push(value, head);
	}
	else
		execute_op(head, opcode, ln);
}

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
	else if (strcmp(opcode, "stack") == 0)
		nop();
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * enqueue - Enqueues an element into the queue
 * @head: Pointer to the queue
 * @n: Value to be enqueued
 */
void enqueue(int n, stack_t **head)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
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
