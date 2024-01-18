#include "monty.h"
/**
* add_dnodeint - add  elemnets at head of  list
* @head: adress of  pointer to dlinkedlist node
* @n:int value added to head of dlinkedlist
* Return: pointer to struct node in case of success, or null
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_all(head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head != NULL)
		(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (new);
}
/**
* free_stack - elemnets in dlinked list
* @h: pointer to dlinkedlist node
* Return: Nothing
*/
void  free_stack(stack_t **h)
{
	stack_t *tmp = NULL, *curr = *h;

	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*h = curr;
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
/**
* stkint_len - prints all elemnets in list
* @h: pointer to dlinkedlist node
* Return: int count
*/
size_t stkint_len(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
