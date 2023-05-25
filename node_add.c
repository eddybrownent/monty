#include "monty.h"

/**
 * add_node - adds a node to the head stack
 * @stack: the head to the stack
 * @num: new integer
 * Return: nothing
 */

void add_node(stack_t **stack, int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(buf.file);
		free(buf.contents);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

}
