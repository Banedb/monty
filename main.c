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
 * main - implement opcodes
 * @argc: argument count
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *opcode = NULL, line[1024], *delim = " \n\t\r", *str_val = NULL;
	int value, ln = 1;
	stack_t *head = NULL;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2 || file == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	for (; fgets(line, sizeof(line), file) != NULL; ln++)
	{
		opcode = strtok(line, delim);
		if (!opcode)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			str_val = strtok(NULL, delim);
			if (valid_num(str_val) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				free_stack(head);
				return (EXIT_FAILURE);
			}
			value = atoi(str_val);
			push(value, &head);
		}
		else if (strcmp(opcode, "pall") == 0)
			print_all(head);
		else
		{
			fprintf(stderr,
				"L%d: unknown instruction %s\n", ln, opcode);
			free_stack(head);
			return (EXIT_FAILURE);
		}
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
