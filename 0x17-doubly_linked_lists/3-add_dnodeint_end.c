#include "lists.h"

/**
 * add_dnodeint_end - a function that adds a new nde at the
 * end of a dlistint_t list.
 * @head: the double pointer to the head of the list.
 * @n: the value to add to the new node.
 *
 * Return: address of new element or NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_alt_node;
	dlistint_t *curnt;

	if (head == NULL)
		return (NULL);

	new_alt_node = malloc(sizeof(dlistint_t));

	if (new_alt_node == NULL)
		return (NULL);

	new_alt_node->n = n;
	new_alt_node->next = NULL;

	if (*head == NULL)
	{
		new_alt_node->prev = NULL;
		*head = new_alt_node;
		return (new_alt_node);
	}

	curnt = *head;
	while (curnt->next != NULL)
		curnt = curnt->next;
	curnt->next = new_alt_node;
	new_alt_node->prev = curnt;
	return (new_alt_node);
}
