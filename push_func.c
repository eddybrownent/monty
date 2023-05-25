#include "monty.h"

/**
 * push_func - to add a node to the stack
 * @counter: line counter
 * @head: the stack head
 *
 * Return: nothing
 */
void push_func(stack_t **head, unsigned int counter)
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
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(buf.file);
			free(buf.contents);
			stack_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(buf.file);
		free(buf.contents);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(buf.arg);
	if (buf.lineflag == 0)
		add_node(head, num);
	else
		add_queue(head, num);
}
