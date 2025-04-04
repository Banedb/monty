#include "monty.h"

unsigned int format = 0;
/**
 * main - x
 * @argc: arg count
 * @argv: arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char line[1024], *opcode, *num;
	FILE *file;
	unsigned int ln;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (ln = 1; fgets(line, 1024, file); ln++)
	{
		opcode = strtok(line, " \n\t\r");
		if (!opcode || opcode[0] == '#')
			continue;
		if (!strcmp("push", opcode))
		{
			num = strtok(NULL, " \n\t\r");
			push(&stack, num, ln);
		}
		else
			execute(&stack, opcode, ln);
	}
	/* printf("printing reverse...\n"); */
	/* print_reverse(stack); */
	fclose(file);
	free_stack(stack);
	return (0);
}
