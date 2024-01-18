#include "monty.h"

list_t list_args = {NULL, NULL, NULL, NULL}; /*define extern variable*/
/**
 *main - main function
 *@argc: number of args
 *@argv: array of args
 *Return: int 1 if success - otherwise 0
 */
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int exit_status;
	stack_t *st = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	list_args.f = fp;
	exit_status = parse_string(list_args.f, &st);
	free(list_args.line);
	free_stack(&st);
	fclose(fp);
	return (exit_status);
}
