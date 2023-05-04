#include "main.h"

/**
 * print_binary - the function that prints the binary
 * representation of a number
 * @n: the number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int w, cnt = 0;
	unsigned long int curnt;

	for (w = 63; w >= 0; w--)
	{
		curnt = n >> w;

		if (curnt & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0);
	}
	if (!cnt)
		_putchar('0');
}
