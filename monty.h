#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned int format;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void execute(stack_t **top, char *opcode, unsigned int ln);
void push(stack_t **top, char *s, unsigned int ln);
void pall(stack_t **top, unsigned int ln);
void pint(stack_t **top, unsigned int ln);
void pop(stack_t **top, unsigned int ln);
void swap(stack_t **top, unsigned int ln);
void add(stack_t **top, unsigned int ln);
void nop(stack_t **top, unsigned int ln);
void sub(stack_t **top, unsigned int ln);
void _div(stack_t **top, unsigned int ln);
void _mul(stack_t **top, unsigned int ln);
void _mod(stack_t **top, unsigned int ln);
void pchar(stack_t **top, unsigned int ln);
void pstr(stack_t **top, unsigned int ln);
void rotl(stack_t **top, unsigned int ln);
void rotr(stack_t **top, unsigned int ln);
void free_stack(stack_t *top);
void print_reverse(stack_t *top);
void push_top(stack_t **head, int n);
void push_bottom(stack_t **head, int n);



#endif /* MONTY_H */
