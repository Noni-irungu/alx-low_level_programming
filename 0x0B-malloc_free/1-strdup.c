#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strdup - duplicate to the new memory space location
 * @str: char
 *
 * Return: 0
 */

char *_strdup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}
	size_t len = strlen(str) + 1;
	char *copy = (char *) malloc(len);

	if (copy == NULL)
	{
		return (NULL);
	}
	memcpy(copy, str, len);
	return (copy);
}

