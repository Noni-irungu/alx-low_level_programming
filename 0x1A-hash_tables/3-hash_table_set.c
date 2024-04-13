#include "hash_tables.h"

/**
 * make_hash_node - A function thaty creates a new hash node.
 * @key: The key for the node.
 * @value: The value for the node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}


/**
 * hash_table_set - A function that sets a key to a value in the hash table.
 * @ht: The hash table to add element to.
 * @key: The key for the data.
 * @value: The data to store.
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *curr_node, *temp;
	char *new_val;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_val = strdup(value);
			if (new_val == NULL)
				return (0);
			free(temp->value);
			temp->value = new_val;
			return (1);
		}
		temp = temp->next;
	}
	curr_node = make_hash_node(key, value);
	if (curr_node == NULL)
		return (0);
	curr_node->next = ht->array[index];
	ht->array[index] = curr_node;
	return (1);
}