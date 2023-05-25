#include "monty.h"
/**
 * pall_func - prints the stack contents
 * @stack: stack head;
 * @line_number: to be used later
 *
 * Return: nothing
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
