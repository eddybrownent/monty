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

int execute_func(char *contents, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t options[] = {{"push", push_func}, {"pall", pall_func}};
	unsigned int i = 0;
	char *opt;

	opt = strtok(contents, " $\n\t");
	if (opt && opt[0] == '#')
		return (0);

	while (options[i].opcode && opt)
	{
		if (strcmp(opt, options[i].opcode) == 0)
		{
			if (strcmp(opt, "push") == 0)
				buf.arg = strtok(NULL, " $\n\t");

			if (buf.arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(file);
				free(contents);
				stack_free(*stack);
				exit(EXIT_FAILURE);
			}
			
			options[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	
	if (opt && options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		fclose(file);
		free(contents);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
