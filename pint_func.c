#include "monty.h"
/**
 * pint_func - prints the int on top of stack
 * @stack: head stack;
 * @line_number: the number of the lin
 *
 * Return: nothing
 *
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(buf.file);
		free(buf.contents);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

