#include "monty.h"

/**
 * nop_a - nothing
 *
 * @stack: stack_t
 * @line_number: number of lines
 *
 * Return: no
*/

void nop_a(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * nodes_swap - swpa the nodes
 *
 * @stack: stack_t
 * @line_number: number of lines
 *
 * Return: no
*/

void nodes_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "swap");
	x = (*stack)->next;
	(*stack)->next = x->next;
	if (x->next != NULL)
		x->next->prev = *stack;
	x->next = *stack;
	(*stack)->prev = x;
	x->prev = NULL;
	*stack = x;
}

/**
 * nodes_add - add nodes
 *
 * @stack: stack_t
 * @line_number: number of lines
 *
 * Return: no
*/

void nodes_add(stack_t **stack, unsigned int line_number)
{
	int x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "add");
	(*stack) = (*stack)->next;
	x = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = x;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nodes_sub - suubtract the nodes
 *
 * @stack: pointer
 * @line_number: int
 *
 * Return: no
*/

void nodes_sub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "sub");
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nodes_div - divide the nodes
 *
 * @stack: pointer
 * @line_number: int
 *
 * Return: no
*/

void nodes_div(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_number, "div");

	if ((*stack)->n == 0)
		more_errors(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
