#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void add_to_stack(stack_t **new,
		__attribute__((unused)) unsigned int linenumber);
void printstack(stack_t **stack, unsigned int linenumber);
void poptop(stack_t **stack, unsigned int linenumber);
void printtop(stack_t **stack, unsigned int linenumber);
void nop_a(stack_t **stack, unsigned int line_number);
void nodes_swap(stack_t **stack, unsigned int line_number);
void nodes_add(stack_t **stack, unsigned int line_number);
void nodes_sub(stack_t **stack, unsigned int line_number);
void nodes_diiv(stack_t **stack, unsigned int line_number);
void more_errors(int error_code, ...);
void errors(int error_code, ...);
void string_errors(int error_code, ...);
void free_nodes(void);
void multiply_nodes(stack_t **stack, unsigned int line_number);
void nodes_mod(stack_t **stack, unsigned int line_number);


#endif
