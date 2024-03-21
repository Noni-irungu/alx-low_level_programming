#include "lists.h"

/**
 * free_dlistint - a function that frees a list.
 * @head: the pointer to the head of the list.
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *latter;

	while (head != NULL)
	{
		latter = head->next;
		free(head);
		head = latter;
	}
}
