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
	free_stack(stack);
	*stack = tmp;
}
