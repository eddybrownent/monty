#include "monty.h"
/**
 * push_func - push an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	int num, x = 0, flag = 0;

	if (buf.arg)
	{
		if (buf.arg[0] == '-')
			x++;
		for (; buf.arg[x] != '\0'; x++)
		{
			if (buf.arg[x] > 57 || buf.arg[x] < 48)
				flag = 1;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(buf.file);
			stack_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(buf.file);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	num = atoi(buf.arg);
	if (buf.lineflag == 0)
		add_node(stack, num);
	else
		add_queue(stack, num);

}
