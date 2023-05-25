#include "monty.h"

/**
 * rotl_func - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *last = *stack;

	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		while (last->next)
			last = last->next;

		*stack = first->next;
		(*stack)->prev = NULL;

		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}
