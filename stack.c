#include "monty.h"
/**
*_push - push new element into stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (list_args.arg2)
	{
		if (is_num(list_args.arg2))
		{
			n = atoi(list_args.arg2);
		}
		else
			int_err(line_number, stack);
	}
	else
	{
		int_err(line_number, stack);
	}
	add_dnodeint(stack, n);
}
/**
* _pall - prints all elemnets in list
* @stack: pointer to stack
* @line_number: file line number
* Return: Nothing
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	print_stack(*stack);
}

/**
*_nop - no operation
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
*_pint - print element at top of stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || (!stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
*_pop - removes element at top of stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!(*stack) || !(stack))
	{
		pop_err(line_number, stack);

	}
	tmp = (*stack)->next;
	if (tmp != NULL)
	{
		tmp->prev = NULL;
	}
	free(*stack);
	*stack = tmp;
}
