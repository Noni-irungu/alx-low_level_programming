#include <stdlb.h>
#include "main.h"

/**
 * array_range - creates an array of integrs filled with numbers
 * from min to max
 * @min: least number of array(minimum)
 * @max: largest number in the array(maximum)
 *
 * Return: pointer to array
 */
int *array_range(int min, int max)
{
	int *ry,
	int i, size;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;

	ry = malloc(sizeof(int) * size);

	if (ry == NULL)
	{
		return (NULL);
	}

	for (i = 0; min <= max; i++)
	{
		ry[i] = min++;
	}
	return (ry);
}
