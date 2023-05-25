#include "monty.h"

/**
 * add_func - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the current opcode
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack && (*stack)->next)
	{
		top = *stack;
		second = top->next;

		second->n += top->n;
		pop_func(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
}
