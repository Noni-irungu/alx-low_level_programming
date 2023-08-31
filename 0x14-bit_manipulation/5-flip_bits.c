#include "main.h"

/**
 * flip_bits - a function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: the first number
 * @m: th second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int t, nonzero = 0;
	unsigned long int latest;
	unsigned long int exclu = n ^ m;

	for (t = 63; t >= 0; t--)
	{
		latest = exclu >> t;
		if (latest & 1)
			nonzero++;
	}

	return (nonzero);
}
