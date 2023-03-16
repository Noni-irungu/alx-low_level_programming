#include <stdlb.h>
#include "main.h"

/**
 * array_range - creates an array of integrs filled with numbers
 * from min to max
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the newly created array
 * if man > mix, returns NULL.
 * if malloc fails, returns NULL.
 */
int *array_range(int min, int max)
{
	int *ar;
	int i;

	if (min > max)
	{
		return (NULL);
	}

	ar = malloc(sizeof(*ar) * ((max - min) + 1));

	if (ar == NULL)
	{
		return (NULL);
	}

	for (i = 0; min <= max; i++)
	{
		ar[i] = min;
	}
	return (ar);
}
