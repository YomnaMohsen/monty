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

	if ((stkint_len(*stack)) < 2 || !(stack) || !(*stack))
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

	if ((stkint_len(*stack)) < 2 || !(stack) || !(*stack))
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
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2 || !(stack) || !(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp->n;
}
