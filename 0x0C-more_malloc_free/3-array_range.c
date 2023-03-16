#include <stdio.h>
#include <string.h>
#include <stdlb.h>
#include "main.h"

/**
 * array_range - creates an array of integrs
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the array
 */
int *array_range(int min, int max)
{
	int i;
	int j;
	int *p;
	int size;

	if (min > max)
	{
		return (NULL);
	}
	size = (max - min) + 1);
	p = malloc(size * sizeof(int);

	if (p == NULL)
		return (NULL);
	j = 0;

	for (i = min; i <= max; i++)
	{
		p[j] = i;
		j++;
	}
	return (p);
}

