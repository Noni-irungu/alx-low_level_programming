#include "main.h"

/**
 * flip_bits - the function that returns the number of bits
 * needed to flip from one number to another
 * @n: the 1st number
 * @m: the 2nd number
 *
 * Return: the number of bits changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a;

	count = 0;
	unsigned long int currnt;
	unsigned long int excu = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		currnt = excu >> a;
		if (currnt & a)
			count++;
	}

	return (count);
}

