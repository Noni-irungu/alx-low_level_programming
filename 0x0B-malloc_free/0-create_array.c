#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @c: character to be checked
 * @size: the byte of c
 *
 * Return: Always 0 (Success)
 */


char *create_array(unsigned int size, char c)
{
	if (size == 0)
	{
		return (NULL);
	}

	char *arr = (char *) malloc(sizeof(char) * size);

	if (arr == NULL)
	{
		return (NULL);
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = c;
	}
	return (arr);
}
