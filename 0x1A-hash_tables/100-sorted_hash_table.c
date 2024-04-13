#include "hash_tables.h"

/**
 * shash_table_create - A function that creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: A pointer to the new table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sort_ht;
	unsigned long int j;

	sort_ht = malloc(sizeof(shash_table_t));
	if (sort_ht == NULL)
		return (NULL);
	sort_ht->size = size;
	sort_ht->shead = NULL;
	sort_ht->stail = NULL;
	sort_ht->array = malloc(sizeof(shash_node_t) * size);
	if (sort_ht->array == NULL)
	{
		free(sort_ht);
		return (NULL);
	}
	for (j = 0; j < size; j++)
	{
		sort_ht->array[j] = NULL;
	}
	return (sort_ht);
}

/**
 * make_shash_node - A function that makes a node for the sorted hash table.
 * @key: The key for the data.
 * @value: The data to be stored.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *sorted_hn;

	sorted_hn = malloc(sizeof(shash_node_t));
	if (sorted_hn == NULL)
		return (NULL);
	sorted_hn->key = strdup(key);
	if (sorted_hn->key == NULL)
	{
		free(sorted_hn);
		return (NULL);
	}
	sorted_hn->value = strdup(value);
	if (sorted_hn->value == NULL)
	{
		free(sorted_hn->key);
		free(sorted_hn);
		return (NULL);
	}
	sorted_hn->next = sorted_hn->snext = sorted_hn->sprev = NULL;
	return (sorted_hn);
}

/**
 * add_to_sorted_list - A function that adds
 * a node to the sorted (by key's ASCII) linked list.
 * @table: the sorted hash table.
 * @node: the node to add.
 *
 * Return: void.
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *curr_node;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	curr_node = table->shead;
	while (curr_node != NULL)
	{
		if (strcmp(node->key, curr_node->key) < 0)
		{
			node->snext = curr_node;
			node->sprev = curr_node->sprev;
			curr_node->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		curr_node = curr_node->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - A function that sets a key to a value in the hash table.
 * @ht: The sorted hash table.
 * @key: The key to the data.
 * @value: The data to add.
 *
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *sorted_hn, *curr_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	curr_node = ht->array[index];
	while (curr_node != NULL)
	{
		if (strcmp(curr_node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(curr_node->value);
			curr_node->value = new_value;
			return (1);
		}
		curr_node = curr_node->next;
	}
	sorted_hn = make_shash_node(key, value);
	if (sorted_hn == NULL)
		return (0);
	sorted_hn->next = ht->array[index];
	ht->array[index] = sorted_hn;
	add_to_sorted_list(ht, sorted_hn);
	return (1);
}

/**
 * shash_table_get - A function that retrieves a value from the hash table.
 * @ht: The hash table.
 * @key: The key to the data.
 *
 * Return: the value associated with key, or NULL on failure.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *curr_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	curr_node = ht->array[index];
	while (curr_node != NULL)
	{
		if (strcmp(curr_node->key, key) == 0)
			return (curr_node->value);
		curr_node = curr_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - A function that prints a sorted hash table.
 * @ht: The hash table to print.
 *
 * Return: void.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr_node;
	char printed_data = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	curr_node = ht->shead;
	while (curr_node != NULL)
	{
		if (printed_data == 1)
			printf(", ");
		printf("'%s': '%s'", curr_node->key, curr_node->value);
		printed_data = 1;
		curr_node = curr_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - A function that prints
 * a sorted hash table in reverse.
 * @ht: The hash table to print.
 *
 * Return: void.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr_node;
	char printed_data = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	curr_node = ht->stail;
	while (curr_node != NULL)
	{
		if (printed_data == 1)
			printf(", ");
		printf("'%s': '%s'", curr_node->key, curr_node->value);
		printed_data = 1;
		curr_node = curr_node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int j;
	shash_node_t *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (j = 0; j < ht->size; j++)
	{
		while (ht->array[j] != NULL)
		{
			next_node = ht->array[j]->next;
			free(ht->array[j]->key);
			free(ht->array[j]->value);
			free(ht->array[j]);
			ht->array[j] = next_node;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
