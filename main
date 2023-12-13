#include "monty.h"

/**
 * push - push an element to top of stack
 * @head: pointer to beginning of stack
 * @num: integer to be added to stack
 */
void push(int num, stack_t **head)
{
	stack_t *stack = malloc(sizeof(stack_t));

	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack->n = num;
	stack->next = *head;
	*head = stack;
}


/**
 * print_all - prints all elements of a listint_t list
 * @h: pointer to head of list
 */
void print_all(const stack_t *h)
{
	const stack_t *current = h;

	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *opcode = NULL, line[1024], *delim = " \n\t\r";
	unsigned int ln = 1;
	stack_t *head = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	for (; fgets(line, sizeof(line), file) != NULL; ln++)
	{
		if (line[0] == '#') /* it's a comment */
			continue;
		opcode = strtok(line, delim);
		if (!opcode)
			continue;
		run_opcode(&head, opcode, ln);
	}
	fclose(file);
	free_stack(head);
	return (0);
}

/**
 * valid_num - checks if a string is a number
 * @str: string to be checked
 *
 * Return: 1 if num, 0 if not
 */
int valid_num(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	/* Check for the '+' or '-' sign */
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
