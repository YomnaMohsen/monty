#include "monty.h"
/**
 * int_err - print err in case invalid int
 * @line_number: file line number that has invalid int
 * Return: Nothing
*/
void int_err(int line_number)
{
	fprintf(stderr, "L %d: usage: push integer\n", line_number);
	free(list_args.line);
	fclose(list_args.f);
	exit(EXIT_FAILURE);
}
