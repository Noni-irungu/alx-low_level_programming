#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: integer(a) is a value to swap
 * @b: integer(b) is a value to swap
 */
void swap_int(int *a, int *b)
{
	int k;

	k = *a;
	*a = *b;
	*b = k;
}
