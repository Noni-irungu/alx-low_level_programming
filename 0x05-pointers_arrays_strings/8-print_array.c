#include "main.h"

/**
 * print_array - a function that prints n elements of an array
 * @a: array name
 * @n: is the number of elements OF the array to be printed
 * Return: a and n inputs
 */
void print_array(int *a, int n)
{
	int w;

	if (n > 0)
	{
		for (w = 0 ; n > w; w++)
		{
			if (w != n - 1)
			{
				printf("%d, ", a[w]);
			}
			else
			{
				printf("%d", a[w]);
			}
		}
	}
	printf("\n");
}
