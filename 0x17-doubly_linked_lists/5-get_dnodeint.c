#include "lists.h"

/**
 * get_dnodeint_at_index - a function that returns the nth
 * node of a dlistint_t linked list.
 * @head: the pointer to the head of the list.
 * @index: the index of the node to find.
 *
 * Return: pointer to the indexed node or NULL on failure.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int j;

	if (head == NULL)
		return (NULL);

	if (index == 0)
		return (head);

	for (j = 0; j < index; j++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
