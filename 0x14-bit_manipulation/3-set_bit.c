#include "main.h"

/**
 * set_bit - the function that sets the value
 * of a bit to 1 at a given index
 * @n: the pointer to which the number is being changed
 * @index: index of bit to set to 1
 *
 * Return: 1(success), -1(failure)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
