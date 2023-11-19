#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/*int m;*/

/**
 * pint - Prints the top value of the stack
 * @line_number: line number in the file
 * @head: Pointer to the first pointer of stack_t
 */

void pint(stack_t **head, unsigned int line_number)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *head;

	printf("%d\n", top->n);
}
/**
 * add_to_emptylist - Adds a node to an empty list
 * @head: Pointer to the first node in stack_t stack
 * @new: Node to be added
 */

void add_to_emptylist(stack_t **head, stack_t *new)
{
	(new)->next = NULL;
	(new)->prev = NULL;
	(new)->n = m;
	*head = new;
}

/**
 * append - Adds a new node to the stack_t stack
 * @head: Pointer to the first node in the stack_t stack
 * @n: Line number of a file
 */

void append(stack_t **head, __attribute__((unused)) unsigned int n)
{
	/*int i;*/
	stack_t __attribute__((unused)) *tmp, *new, *prev, *next;

	new = (stack_t *) malloc(sizeof(new));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = m;
	/*tmp = *head;*/

	/* if list is empty, make new the first pointer */
	if (*head == NULL)
	{
		/* add_to_emptylist(head, new); */
		/*printf("tis is null\n");*/
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		/*printf("n: %d\n", (*head)->n);*/
	}
	else
	{
		tmp = *head;

		/* Traverse the list till the last node added */
		/* tmp->prev; tmp = tmp->prev */
		for (; tmp->next; tmp = tmp->next)
		{
		}
		/* Put the new node at the begining of the list */
		/* tmp->prev = new;*/
		 /* tmp->next = tmp */
		 /* new->prev = NULL;*/
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
		*head = new;
	}
}

/**
 * pop - Pops a node from the top of a stack_t stack
 * @line_number: Number of a line in the file
 * @head: Node to the top node of the stack_ta
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->prev;
	free(*head);
	*head = tmp;	
}

/**
 * print_list - Prints all elements of a stack_t stack
 * from top to bottom
 * @head: Pointer to the first node in the stack_t stack
 * @line_number: Line number of the file
 */
void print_list(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	/* tmp = *head; */
	if (*head == NULL)
	{
		exit(EXIT_FAILURE);
		free(head);
	}
	else
	{
		tmp = *head;
		while (tmp)
		{
			printf("%d\n", tmp->n);
			if (!tmp->n)
				fprintf(stderr, "L%i: usage: push integer\n",
						line_number);
			/*tmp = *head;*/
			/* head = head->prev */
			tmp = tmp->prev;
		}
	}
}
