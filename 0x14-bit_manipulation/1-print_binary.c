#include "main.h"

/**
 * print_binary - a function that prints the binary
 * representation of a number.
 * @n: the number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int t, cnt = 0;
	unsigned long int curnt;

	for (t = 63; t >= 0; t--)
	{
		curnt = n >> t;

		if (curnt & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}
