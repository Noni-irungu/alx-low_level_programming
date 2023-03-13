#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @c: character to be checked
 * @size: the byte of c
 * size = 0: Returns NULL
 * size != 0: Returns a pointer to the array or NULL
 *
 * Return: Always 0 (Success)
 */


char *create_array(unsigned int size, char c)
{
	char *arr = NULL;  /*initialize array pointer to NULL*/

	if (size == 0)
	{
		return (NULL); /*return NULL if size = 0*/
	}

	arr = malloc(size * sizeof(char));  /*allocate memory for the array*/

	if (arr == NULL)
	{
		return (NULL);  /*return NULL if memory allocation fails*/
	}

	for (unsigned int i = 0; i < size; i++)
	{
		arr[i] = c;  /*initialize the array with the specific char*/
	}
	return (arr);  /*return the pointer to the array*/
}
