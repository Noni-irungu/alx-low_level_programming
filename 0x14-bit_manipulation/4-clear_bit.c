#include "main.h"

/**
 * clear_bit - a function that sets the value of a given bit to 0.
 * @n: the pointer to the  umber to change.
 * @index: the index of the bit to be cleared.
 *
 * Return: (1) if success, (-1) if failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
