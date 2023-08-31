#include "main.h"

/**
 * set_bit - a function that sets a bit at agiven index to 1
 * @n: the number to be changed
 * @index: the index of the bit to set to 1
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
