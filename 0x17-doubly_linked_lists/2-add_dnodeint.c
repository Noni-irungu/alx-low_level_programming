#include "lists.h"

/**
 * add_dnodeint - a function that adds a new node at the
 * beginning of a dlistint_t list.
 * @head: the pointer to the head of the linked list.
 * @n: the value to add to the new node
 *
 * Return: the pointer to the new node, NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_alt_node;

	if (head == NULL)
		return (NULL);

	new_alt_node = malloc(sizeof(dlistint_t));

	if (new_alt_node == NULL)
		return (NULL);

	new_alt_node->n = n;
	new_alt_node->prev = NULL;
	new_alt_node->next = *head;
	*head = new_alt_node;

	if (new_alt_node->next != NULL)
		(new_alt_node->next)->prev = new_alt_node;
	return (new_alt_node);
}
