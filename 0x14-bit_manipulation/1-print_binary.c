#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be printed in binary
 * @printed: hold the number of characters printed
 */
void print_binary(unsigned int n, unsigned int *printed)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
