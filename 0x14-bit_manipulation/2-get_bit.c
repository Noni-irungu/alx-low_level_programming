#include "main.h"

/**
 * get_bit - a function that returns the value of a bit
 * at an index in decimal number.
 * @n: the umber to search for.
 * @index: the index of the bit.
 *
 * Return: the value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
