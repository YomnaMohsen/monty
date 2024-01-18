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
		return (NULL);
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

