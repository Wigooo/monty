#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openfile(argv[1]);
	free_nodes();
	return (0);
}

/**
 * createnode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *createnode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tempo;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tempo = head;
		head = head->next;
		free(tempo);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new: Pointer to the new node.
 * @lnumber: line number of the opcode.
 */
void add_to_queue(stack_t **new, __attribute__((unused))unsigned int lnumber)
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
	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *new;
	(*new)->prev = tempo;

}
