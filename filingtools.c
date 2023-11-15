#include "monty.h"

/**
 * openfile - opens a file
 * @filename: the file namepath
 * Return: void
 */

void openfile(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
		errors(2, filename);

	readfile(fd);
	fclose(fd);
}


/**
 * readfile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readfile(FILE *fd)
{
	int linenumber, f = 0;
	char *buff = NULL;
	size_t length = 0;

	for (linenumber = 1; getline(&buff, &length, fd) != -1; linenumber++)
	{
		f = parse_line(buff, linenumber, f);
	}
	free(buff);
}


/**
 * parseline - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @linenumber: line number
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buff, int linenumber, int f)
{
	char *opcode, *value;
	const char *delimeter = "\n ";

	if (buff == NULL)
		errors(4);

	opcode = strtok(buff, delimeter);
	if (opcode == NULL)
		return (f);
	value = strtok(NULL, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findfunc(opcode, value, linenumber, f);
	return (f);
}

/**
 * findfunc - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @f:  storage format. If 0 Nodes will be entered as a stack.
 * @lnumber: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findfunc(char *opcode, char *value, int lnumber, int f)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", printstack},
		{"pint", printtop},
		{"pop", poptop},
		{"nop", nop_a},
		{"swap", nodes_swap},
		{"add", nodes_add},
		{"sub", nodes_sub},
		{"div", nodes_div},
		{"mul", multiply_nodes},
		{"mod", nodes_mod},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", rotatel},
		{"rotr", rotater},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callfun(func_list[i].f, opcode, value, lnumber, f);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, lnumber, opcode);
}


/**
 * callfun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callfun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = createnode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
