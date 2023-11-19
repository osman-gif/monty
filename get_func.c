#include "monty.h"

/*unsigned int line_n;*/

/**
 * get_op_func - Gets desired function bassed on its argument (s)
 * @s: String representing the operation
 * Return: Pointer to a fucntion that returns void and
 * accpet two arguments one of type stack_t and the other
 * of type unsigned int
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", append},
		{"pall", print_list},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, s) == 0)
		{
			/*printf("yes: %s == %s\n", ops[i].opcode, s);*/
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * free_stack - Frees the stack_t stack
 * @head: Pointer to the first pointer
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
	{
		printf("NULL\n");
	}
	while (head)
	{
		tmp = (head)->prev;
		free(head);
		head = tmp;
	}
}
