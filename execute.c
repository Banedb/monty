#include "monty.h"

/**
 * execute - match opcode to instruction
 * @stack: top of the stack
 * @opcode: instruction
 * @ln: line number of instruction
 *
 */
void execute(stack_t **stack, char *opcode, unsigned int ln)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(instructions[i].opcode, opcode))
		{
			instructions[i].f(stack, ln);
			return;
		}
		else if (!strcmp("stack", opcode))
		{
			format = 0;
			return;
		}
		else if (!strcmp("queue", opcode))
		{
			format = 1;
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	exit(EXIT_FAILURE);
}
