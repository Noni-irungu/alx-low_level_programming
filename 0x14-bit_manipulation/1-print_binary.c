#include "main.h"

/**
 * print_binary - the function that prints the binary rep of a number
 * @n: the number to be printed in binary
 *
 * Return: 0(success)
 */
void print_binary(unsigned long int n)
{
	int j = 0;

	count = 0;
	unsigned long int currnt;

	for (j = 63; w >= 0; j--)
	{
		currnt = n >> j;

		if (currnt & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0);
	}
	if (!count)
		_putchar('0');
}
