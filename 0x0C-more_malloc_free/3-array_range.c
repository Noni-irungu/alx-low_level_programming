#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * array_range - creates an array of integrs filled with numbers
 * from min to max
 * @min: first number of array
 * @max: largest number in the array
 *
 * Return: pointer to new array, Null if failed.
 */
int *array_range(int min, int max)
{
	int *ry;
	int i, size, n;

	if (min > max)
	{
		return (NULL);
	}
	size = max - min;
	ry = malloc(size + 1) sizeof(int));
	i = 0;
	n = min;
	while (n <= max)
	{
		ry[i] = n;
		i++;
		n++;
	}
	return (ry);
}
