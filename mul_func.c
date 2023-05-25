#include "monty.h"

/**
 * mul_func - multiplies the second top element with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
