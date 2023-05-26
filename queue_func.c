#include "monty.h"

/**
 * queue_func - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void queue_func(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Unused parameter */
	(void)line_number; /* Unused parameter */
	buf.lineflag = 1;

}

/**
 * addqueue - add a node to the tail of the stack
 * @n: new value
 * @head: head of the stack
 * Return: no return
 */
void add_queue(stack_t **stack, int num)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(buf.file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
}



