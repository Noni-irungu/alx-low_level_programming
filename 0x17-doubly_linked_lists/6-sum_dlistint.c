#include "lists.h"

/**
 * sum_dlistint - a function that returns the sum of all
 * the data (n) of a dlistint_t linked list.
 * @head: the pointer to the first node.
 *
 * Return: the sum of data, or 0 if list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum_mation = 0;

	while (head != NULL)
	{
		sum_mation += head->n;
		head = head->next;
	}
	return (sum_mation);
}
