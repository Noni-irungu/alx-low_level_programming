#include "main.h"

/**
 * _strncpy - a functions that copies a string
 * @dest: input value
 * @src: input value
 * @n: input value
 * Return: Always (0)
 *
 */
char *_strncpy(char *dest, char *src, int n)
{
	int u = 0;

		for (u = 0; u < n && src[u] != '\0'; u++)
			dest[u] = src[u];
		for ( ; u < n; u++)
			dest[u] = '\0';

	return (dest);
}
