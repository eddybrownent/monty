#include "monty.h"
/**
 * queue_func - prints the top of stack
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void queue_func(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	buf.lineflag = 1;
}

/**
 * add_queue - add node to the tail of stack
 * @num: new_value
 * @head: head of the stack
 * Return: nothing
*/
void add_queue(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = num;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
