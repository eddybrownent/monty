#include "monty.h"

/**
 * add_node - adds a node to the head stack
 * @head: the head to the stack
 * @num: new integer
 * Return: nothing
 */

void add_node(stack_t **head, int num)
{
	stack_t *new_node, *stk;

	stk = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (stk)
		stk->prev = new_node;
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
