#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_s - varibles ie args file and line contents
 * @arg: the value
 * @file: pointer to the file
 * @contents: line contents
 * @lineflag: change stack queue
 * Description: to carry values through the program
 */
typedef struct buf_s
{
	char *arg;
	FILE *file;
	char *contents;
	int lineflag;
}  buf_t;
extern buf_t buf;

void queue_func(stack_t **head, unsigned int counter);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void execute(stack_t **stack, unsigned int counter, char *contents, FILE *file);
void sub_func(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int num);
void div_func(stack_t **stack, unsigned int line_number);
void stack_free(stack_t *head);
int is_valid_integer(const char *str);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
void rotl_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, unsigned int line_number);
void queue_func(stack_t **stack, unsigned int line_number);
void add_queue(stack_t **stack, int num);
void stack_func(stack_t **stack, unsigned int line_number);

#endif
