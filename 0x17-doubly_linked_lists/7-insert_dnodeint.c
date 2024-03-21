#include "lists.h"

/**
 * insert_dnodeint_at_index - a function that inserts a new
 * node at a specified index.
 * @h: the pointer to the head of the list.
 * @idx: the index at which to insert the new node.
 * @n: the data t enter into the new node.
 *
 * Return: the pointer to the new node or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_alt_node;
	dlistint_t *curnt;
	dlistint_t *latter;
	unsigned int j;

	if (h == NULL)
		return (NULL);

	if (idx != 0)
	{
		curnt = *h;
		for (j = 0; j < idx - 1 && curnt != NULL; j++)
			curnt = curnt->next;
		if (curnt == NULL)
			return (NULL);
	}

	new_alt_node = malloc(sizeof(dlistint_t));

	if (new_alt_node == NULL)
		return (NULL);
	new_alt_node->n = n;
	if (idx == 0)
	{
		latter = *h;
		*h = new_alt_node;
		new_alt_node->prev = NULL;
	}
	else
	{
		new_alt_node->prev = curnt;
		latter = curnt->next;
		curnt->next = new_alt_node;
	}
	new_alt_node->next = latter;
	if (new_alt_node->next != NULL)
		new_alt_node->next->prev = new_alt_node;
	return (new_alt_node);
}
