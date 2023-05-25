#include "monty.h"

/**
 * rotr_func - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		while (last->next)
			last = last->next;


		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}
