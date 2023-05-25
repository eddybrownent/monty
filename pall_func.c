#include "monty.h"
/**
 * pall_func - prints the stack contents
 * @head: stack head;
 * @counter: to be used later
 *
 * Return: nothing
 */

void pall_func(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	(void) counter;

	hd = *head;
	if (hd == NULL)
		return;
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}
