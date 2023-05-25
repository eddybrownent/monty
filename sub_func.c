#include "monty.h"

/**
 * sub_func - Sub the top element of the stack from the second top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 *
 */

void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
