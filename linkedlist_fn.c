#include "monty.h"

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
* free_dlistint -  elemnets in dlinked list
* @h: pointer to dlinkedlist node
* Return: Nothing
*/
void  free_stack(stack_t **h)
{
	stack_t *tmp= NULL, *curr = *h;
	
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*h = curr;
}

