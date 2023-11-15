#include "monty.h"

/**
 * multiply_nodes - multiply the nodes
 *
 * @stack: pointer
 * @line_number: the no. of the lines
 *
 * Return: no
*/

void multiply_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nodes_mod - mod of the nodes
 *
 * @stack: poiinter
 * @line_number: no. of lines
 *
 * Return: no
*/

void nodes_mod(stack_t **stack, unsigned int line_number)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "mod");

	if ((*stack)->n == 0)
		more_errors(9, line_number);

	(*stack) = (*stack)->next;
	x = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
