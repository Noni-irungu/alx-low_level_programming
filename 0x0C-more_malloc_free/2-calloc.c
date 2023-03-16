#include "main.h"

/**
 * _calloc - a function that allocates memory for an array
 * @nmemb: number of elements in array
 * @size: size of array
 *
 * Return: pointer string
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *h;

	if (nmemb == 0 || size == 0)
		return (NULL);

	h = malloc(nmemb * size);

	if (h == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		*(h + i) = 0;

	return (h);
}
