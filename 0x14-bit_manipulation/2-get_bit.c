#include "main.h"

/**
 * get_bit - a function that returns the valueof a bit at an index
 * in decimal number.
 * @n: the number to search
 * @index: the index of the bit
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bitrate;

	if (index > 63)
		return (-1);

	bitrate = (n >> index) & 1;

	return (bitrate);
}
