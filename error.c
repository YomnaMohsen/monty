#include "monty.h"
/**
 * int_err - print err in case invalid int
 * @line_number: file line number that has invalid int
 * @s: address of pointer to head
 * Return: Nothing
*/
void int_err(int line_number, stack_t **s)
{
	(void) s;
	
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
/*	free_all(s);*/
	exit(EXIT_FAILURE);
}
/**
 * pop_err - print err in case pop empty stack
 * @line_number: file line number contains invalid pop
 * @s: address of pointer to head
 * Return: Nothing
*/
void pop_err(int line_number, stack_t **s)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_all(s);
	exit(EXIT_FAILURE);

}
/**
 * free_all - frees all allocated memory and close file
 * @s: address of pointer to head
 * Return: Nothing
*/
void free_all(stack_t **s)
{
	free(list_args.line);
	free_stack(s);
	fclose(list_args.f);
}
