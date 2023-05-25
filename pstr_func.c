#include "monty.h"

/**
 * pstr_func - Prints the string starting from the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the current opcode
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{

	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		if (current->n == ' ')
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
