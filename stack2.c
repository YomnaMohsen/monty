#include "monty.h"
/**
*_mul - adds the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	tmp = (*stack)->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
/**
*_div - adds the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_all(stack);
		exit(EXIT_FAILURE);
    }
	(*stack)->next->n /= (*stack)->n;
	tmp = (*stack)->next;
	/*tmp->prev = NULL;*/
	free(*stack);
	*stack = tmp;
}
/**
*_mod - adds the top two elements of the stack
*@stack: pointer to top of stack
*@line_number: line number of instruction
*Return: Nothing
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((stkint_len(*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_all(stack);
        exit(EXIT_FAILURE);
    }
	(*stack)->next->n %= (*stack)->n;
	tmp = (*stack)->next;
    free(*stack);
	/*tmp->prev = NULL;*/
	*stack = tmp;
}