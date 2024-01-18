#include "monty.h"
/**
 * int_err - print err in case invalid int
 * @line_number: file line number that has invalid int
 * Return: Nothing
*/
void int_err(int line_number, stack_t **s)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(list_args.line);
	free_stack(s);
	fclose(list_args.f);
	exit(EXIT_FAILURE);
}
/**
 * pop_err - print err in case pop empty stack
 * @line_number: file line number contains invalid pop
 * Return: Nothing
*/
void pop_err(int line_number, stack_t **s)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free(list_args.line);
	free_stack(s);
	fclose(list_args.f);
	exit(EXIT_FAILURE);

}