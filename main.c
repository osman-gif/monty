#include "monty.h"

int m;
/**
 * execute_func - execute a function based on the opcode read from a  file
 * against the stack_t stack
 * @opcode: Operation code (pall, push etc.);
 * @line_n: line number of a file being read
 * @head: Pointer to the first node in the stack_t stack
 */

void execute_func(char *opcode, unsigned int line_n, stack_t **head)
{
	void (*fp)(stack_t **stack, unsigned int line_number);

	fp = get_op_func(opcode);
	fp(head, line_n);
}
/**
 * operate_on_stack - Does some stack operations on stack_t
 * based on line read from a file
 * @line: Line read from a file
 * @n: Bytes read from a file (size of line) in bytes
 * @file: File being read
 * @head: Pointer to the first node in the stack
 */

void operate_on_stack(char **line, size_t *n, FILE *file, stack_t **head)
{
	char *opcode, *argstr, *delim;
	unsigned int line_n;
	/* void (*fp)(stack_t **stack, unsigned int line_number); */
	int arg;

	delim = " \n\0";
	line_n = 0;
	while (getline(line, n, file) != -1)
	{
		line_n++;
		opcode = strtok(*line, delim);
		if (strcmp("push", opcode) == 0)
		{
			argstr = strtok(NULL, delim);
			if (!argstr)
			{
				fprintf(stderr,  "L%i: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
			else
			{
				arg = atoi(argstr);
				if (!arg)
				{
					fprintf(stderr, "L%i: usage: push integer\n", line_n);
					exit(EXIT_FAILURE);
				}
			}
			m = arg;
			execute_func(opcode, line_n, head);

			/* fp = get_op_func(opcode); */
			/* fp(head, line_n); */
		}
		else if (strcmp("pall", opcode) == 0)
			execute_func(opcode, line_n, head);
		else if (strcmp("pint", opcode) == 0)
			execute_func(opcode, line_n, head);
		else if (strcmp("pop", opcode) == 0)
			execute_func(opcode, line_n, head);
		else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n",
					line_n, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * main - Test code
 * @argc: Number of arguments passed to the program
 * @argv: Arguments passed to the program
 * Return: Always 0
 */
int main(int argc, char __attribute__((unused)) **argv)
{
	char *line;
	size_t n;
	FILE *file;
	stack_t *head;
	__attribute__((unused)) int arg;

	head = NULL;
	line = NULL;
	n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	operate_on_stack(&line, &n, file, &head);
	fclose(file);
	free_stack(head);

	return (0);
}
