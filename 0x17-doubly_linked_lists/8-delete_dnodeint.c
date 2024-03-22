#include "lists.h"

/**
 * delete_dnodeint_at_index - a function that deltes
 * a node at a given index.
 * @head: a pointer to the first node of linked list.
 * @index: the index at which to delete the node.
 *
 * Return: (1) on success and (-1) on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curnt;
	unsigned int j;

	if (head == NULL || *head == NULL)
		return (-1);

	curnt = *head;
	if (index == 0)
	{
		*head = curnt->next;
		if (curnt->next != NULL)
		{
			curnt->next->prev = NULL;
		}
		free(curnt);
		return (1);
	}

	for (j = 0; j < index; j++)
	{
		if (curnt->next == NULL)
			return (-1);
		curnt = curnt->next;
	}
	curnt->prev->next = curnt->next;
	if (curnt->next != NULL)
		curnt->next->prev = curnt->prev;
	free(curnt);
	return (1);
}
