#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int format;
int valid_num(const char *str);
void free_stack(stack_t *head);
void mod(stack_t **head, unsigned int ln);
void mul(stack_t **head, unsigned int ln);
void pint(stack_t *head, unsigned int ln);
void pchar(stack_t **head, unsigned int ln);
void pstr(stack_t **head);
void pop(stack_t **head, unsigned int ln);
void print_all(const stack_t *h);
void push(int num, stack_t **head);
void handle_opcode(stack_t **head, char *opcode, unsigned int ln);
void stack_div(stack_t **head, unsigned int ln);
void sub(stack_t **head, unsigned int ln);
void enqueue(int n, stack_t **head);
void add(stack_t **stk, unsigned int l);
void swap(stack_t **stk, unsigned int l);
void nop(void);
void rotl(stack_t **stk);
void rotr(stack_t **stk);
void execute_op(stack_t **head, char *opcode, unsigned int ln);
#endif
