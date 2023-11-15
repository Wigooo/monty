#include "monty.h"

/**
 * print_character - print the character
 *
 * @stack: pointer
 * @line_number: int
 *
 * Return: no
*/

void print_character(stack_t **stack, unsigned int line_number)
{
	int x;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_number);

	x = (*stack)->n;
	if (x < 0 || x > 127)
		string_errors(10, line_number);
	printf("%c\n", x);
}

/**
 * print_string - rint the string
 *
 * @stack: pointer
 * @ln: int
 *
 * Return: no
*/

void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int x;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		x = tmp->n;
		if (x <= 0 || x > 127)
			break;
		printf("%c", x);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotatel - rotate
 *
 * @stack: pointer
 * @ln: int
 *
 * Return: no
*/

void rotatel(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotater - rotate
 *
 * @stack: pointer
 * @ln: int
 *
 * Return: no
*/

void rotater(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
