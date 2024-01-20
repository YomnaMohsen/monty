#include "monty.h"
/**
*_add - adds the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	tmp = (*stack)->next;
	if (tmp != NULL)
	{
		tmp->prev = NULL;
	}
	free(*stack);
	*stack = tmp;
}
/**
*_sub - subs the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	tmp = (*stack)->next;
	if (tmp != NULL)
	{
		tmp->prev = NULL;
	}
	free(*stack);
	*stack = tmp;
}
/**
*_swap - swaps the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
/**
*_pchar - print char at top of stack of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!(*stack) || !(stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n < 33 || n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}