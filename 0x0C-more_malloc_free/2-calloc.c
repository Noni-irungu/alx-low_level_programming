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
	unsigned int ar_size, i;
	char *h;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ar_size = nmemb * size;

	h = malloc(ar_size);

	if (ar == NULL)
		return (NULL);

	while (i < ar_size)
	{
		ar[i] = 0;
		i++;
	}

	return (ar);
}
