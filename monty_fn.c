#include "monty.h"
#include <string.h>

/**
*get_func - matches opcode with func in line
*@opcode: pointer to opcode string
*Return: if function found return pointer to it
*          otherwise null
*/
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int j;


	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"nop", _nop},
		{ NULL, NULL}
	};
	for (j = 0; opcodes[j].f; j++)
	{
		if (strcmp(opcode, opcodes[j].opcode) == 0)
		{
			return (opcodes[j].f);
		}
	}
	return (NULL);
}
/**
* parse_string - parse instruction string
* @fp: pointer to file datatype
* @s: pointer to stack
* Return: int 1 if success - otherwise 0
*/
int parse_string(FILE *fp, stack_t **s)
{
	char  *delim = " \n\t";
	size_t n = 0;
	int line_num = 0;
	void (*f)(stack_t**, unsigned int);

	while (getline(&list_args.line, &n, fp) != -1)
	{
		line_num++;
		if (check_empty(list_args.line))
		{
			continue;
		}
		list_args.arg1 = strtok(list_args.line, delim);
		list_args.arg2 = strtok(NULL, delim);
		if (list_args.arg1[0] == '#')
		{
			_nop(s, line_num);
			return (0);
		}
		f = get_func(list_args.arg1);
		if (f == NULL)
		{
			fprintf(stderr, "L %d: unknown instruction %s", line_num, list_args.arg1);
			return (EXIT_FAILURE);
		}
		f(s, line_num);
	}
	return (0);
}

/**
 * check_empty - check if line is empty
 * @line: string of instruction
 * Return: int 1 if success - otherwise 0
*/
int check_empty(char *line)
{
	int i, j;
	char *delim = " \n\t\a";

	for (i = 0; line[i] != '\0'; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * is_num - checks if string is valid no
 * @str: string of instruction
 * Return: int 1 if success - otherwise 0
*/
int is_num(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}

	return (1);
}
