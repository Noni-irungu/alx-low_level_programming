#include "main.h"

/**
 * char*_strcpy - a function that copies the string pointed to by src
 * @dest: copy to (array)
 * @src: copy from (number of array)
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int j;

	for (j = 0; src[j]; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = src[j];
	return (dest);
}
