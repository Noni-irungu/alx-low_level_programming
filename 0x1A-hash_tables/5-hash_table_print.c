#include "hash_tables.h"

/**
 * hash_table_print - A function that prints a hash table.
 * @ht: The hash table to print.
 *
 * Return: void.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *tmp;
	char printed_data = 0; /* 0 while no data has been printed yet */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (j = 0; j < ht->size; j=j+1)
	{
		tmp = ht->array[j];
		while (tmp != NULL)
		{
			if (printed_data == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			printed_data = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}