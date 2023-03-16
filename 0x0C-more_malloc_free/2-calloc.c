#include "main.h"

/**
 * _memset - copy char
 * @s: string
 * @b: input
 * @n: bytes
 * Return: string
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int g;

	for (g = 0; g < n; g++)
	{
		s[i] = b;
	}
	return (s);
}
/**
 * _calloc - a function that allocates memory for an array
 * @nmemb: number of elements in array
 * @size: size of array
 *
 * Return: pointer string
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *z;

	if (nmemb == 0 || size == 0)
		return (NULL);

	h = malloc(nmemb * size);

	if (h == NULL)
		return (NULL);
	_memset(h, 0, (nmemb * size));
	return (h);
}
