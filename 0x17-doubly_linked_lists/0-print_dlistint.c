#include "lists.h"

/**
 * print_dlistint - a function that prints all the elements
 * of a dlistint_t list.
 * @h: the pointer to the head node.
 *
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int nd_cnt;

	nd_cnt = 0;

	if (h == NULL)
		return (nd_cnt);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nd_cnt++;
	}

	return (nd_cnt);
}
