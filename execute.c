#include "monty.h"
/**
 * execute - to execute the opcodes
 * @stack: head of the linked list ie stack
 * @counter: to count
 * @contents: carries the line contents
 * @file: monty file pointer
 * Return: nothing
 *
 */

void execute(stack_t **stack, unsigned int counter, char *contents, FILE *file)
{
	instruction_t options[] = {
		{"push", push_func}, {"pall", pall_func}, {"pint", pint_func},
		{"pop", pop_func}, {"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {"sub", sub_func}, {"div", div_func},
		{"mul", mul_func}, {"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"queue", queue_func},
		{"stack", stack_func},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opt;

	opt = strtok(contents, " \n\t");
	if (opt && opt[0] == '#')
		return;

	buf.arg = strtok(NULL, " \n\t");

	while (options[i].opcode && opt)
	{
		if (strcmp(opt, options[i].opcode) == 0)
		{
			options[i].f(stack, counter);
			return;
		}
		i++;
	}
	if (opt && options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		fclose(file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
}
