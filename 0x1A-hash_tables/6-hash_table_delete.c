#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (j = 0; j < ht->size; j = j + 1)
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
	ht->size = 0;
	free(ht);
}
