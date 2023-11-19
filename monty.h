#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int m;
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

void free_stack(stack_t *head);
void pint(stack_t **head, unsigned int line_number);
void read_file(int *, char **, char*, stack_t **);
void add_to_emptylist(stack_t **head, stack_t *new);
void append(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);
void print_list(stack_t **head, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
#endif
