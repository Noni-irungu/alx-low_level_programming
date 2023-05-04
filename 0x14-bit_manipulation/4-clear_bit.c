#include "main.h"

/**
 * clear_bit - the function that sets the value
 * of a bit to 0 at a given index
 * @n: the pointer to which the number is being changed
 * @index: the index of bit to clear
 *
 * Return: 1(success), -1(failure)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
