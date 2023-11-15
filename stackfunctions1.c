#include "monty.h"

/**
 * add_to_stack - adding node to stack
 * @new: pointer to newnode
 * @linenumber: integer represting line number of opcode
*/

void add_to_stack(stack_t **new, __attribute__((unused))
		unsigned int linenumber)
{
	stack_t *tempo;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tempo = head;
	head = *new;
	head->next = tempo;
	tempo->prev = head;
}

/**
 * printstack - adds a node to the stack
 * @stack: pointer to pointer to top node of stack
 * @linenumber: line number of opcode
*/

void printstack(stack_t **stack, unsigned int linenumber)
{
	stack_t *tempo;

	(void) linenumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tempo = *stack;
	while (tempo != NULL)
	{
		printf("%d\n", tempo->n);
		tempo = tempo->next;
	}
}

/**
 * poptop - deletes node from stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of opcode
 */
void poptop(stack_t **stack, unsigned int linenumber)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL)
		more_errors(7, linenumber);
	tempo = *stack;
	*stack = tempo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tempo);
}
/**
 * printtop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of of the opcode.
 */
void printtop(stack_t **stack, unsigned int linenumber)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, linenumber);
	printf("%d\n", (*stack)->n);
}
