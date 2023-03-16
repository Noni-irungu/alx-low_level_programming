#include "main.h"

/**
 * array_range - creates an array of integrs filled with numbers
 * from min to max
 * @min: least number of array(minimum)
 * @max: largest number in the array(maximum)
 *
 * Return: pointer to new array, Null if failed.
 */
int *array_range(int min, int max)
{
	int *ry, i = 0, k = min;

	if (min > max)
	{
		return (0);
	}

	ry = malloc(max - min + 1) * sizeof(int));

	if (!ry)
	{
		return (0);
	}
	while (i <= max - min)
	{
		ry[i++] = k++;
	}
	return (ry);
}
