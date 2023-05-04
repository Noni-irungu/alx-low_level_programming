#include "main.h"

/**
 * print_binary - the function that prints the binary rep of a number
 * @n: the number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int j, cnt = 0;
	unsigned long int curnt;

	for (j = 63; j >= 0; j--)
	{
		curnt = n >> j;

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
