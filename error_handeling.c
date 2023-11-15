#include "monty.h"

/**
 * errors - pritn the errors
 *
 * @error_code: int
 *
 * Return: no
*/

void errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int x;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			x = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", x, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - more errors
 *
 * @error_code: int
 *
 * Return: no
*/

void more_errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int x;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(ag, int));
			break;
		case 8:
			x = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", x, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - string errors
 *
 * @error_code: int
 *
 * Return: no
*/

void string_errors(int error_code, ...)
{
	va_list ag;
	int x;

	va_start(ag, error_code);
	x = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", x);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", x);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
