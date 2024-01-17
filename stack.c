#include "monty.h"
/**
 * 
*/
void _push(stack_t **stack, unsigned int line_number)
{
    int n;
    if (list_args.arg2 == NULL)
    {
        int_err(line_number);
    }
    if (atoi(list_args.arg2) == 0 && list_args.arg2[0] != '0')
    {
        int_err(line_number);
    }
    n = atoi(list_args.arg2);
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
* print_stack - prints all elemnets in stack
* @h: pointer to top of stack
* Return: Nothing
*/
void print_stack(const stack_t *h)
{
    while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}