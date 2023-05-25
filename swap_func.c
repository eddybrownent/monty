#include "monty.h"

/**
 * swap_func - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack && (*stack)->next)
	{
		top = *stack;
		second = top->next;

		top->prev = second;
		top->next = second->next;
		if (second->next)
			second->next->prev = top;
		second->prev = NULL;
		second->next = top;


		*stack = second;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
}
