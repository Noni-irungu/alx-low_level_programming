#include "lists.h"

/**
 * dlistint_len - a function that returns the number of elements
 * in a linked dlistint_t list.
 * @h: the pointer to the head of the linked list.
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t j;

	for (j = 0; h != NULL; j++)
		h = h->next;
	return (j);
}
