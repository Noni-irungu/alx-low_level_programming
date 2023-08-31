#include "main.h"

/**
 * print_binary - a function that prints the
 * binary representation of a number.
 * @n: number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	int t, nonzero = 0;
	unsigned long int latest;

	for (t = 63; t >= 0; t--)
	{
		latest = n >> t;

		if (latest & 1)
		{
			_putchar('1');
			latest++;
		}
		else if (latest)
			_putchar('0');
	}
	if (!latest)
		_putchar('0');
}
