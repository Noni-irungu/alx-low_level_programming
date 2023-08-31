#include "main.h"

/**
 * print_binary - a function that prints the
 * binary representation of a number.
 * @n: number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	int t;
	int nonzero;

	unsigned long int latest;

	t = 0;
	nonzero = 0;

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
	if (latest == NULL)
		_putchar('0');
}
