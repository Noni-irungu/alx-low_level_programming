#include "main.h"

/**
 * flip_bits - a function that counts the number of bits to change to
 * get from one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits to be changed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int h, cnt = 0;
	unsigned long int curnt;
	unsigned long int exve = n ^ m;

	for (h = 63; h >= 0; h--)
	{
		curnt = exve >> h;
		if (curnt & 1)
			cnt++;
	}

	return (cnt);
}
