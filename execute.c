#include "monty.h"

/**
 * execute_func - to execute the opcodes
 * @stack: head of the linked list ie stack
 * @counter: to count
 * @contents: carries the line contents
 * @file: monty file pointer
 * Return: nothing
 *
 */

void execute_func(stack_t **stack, unsigned int counter, char *contents, FILE *file)
{
	instruction_t options[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opt;

	opt = strtok(contents, " \t\n");
	if (opt && opt[0] == '#')
		return;

	buf.arg = NULL;

	while (options[i].opcode && opt)
	{
		if (strcmp(opt, options[i].opcode) == 0)
		{
			if (strcmp(opt, "push") == 0)
				buf.arg = strtok(NULL, " $\t\n");

			options[i].f(stack, counter);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
	fclose(file);
	stack_free(*stack);
	exit(EXIT_FAILURE);
}
