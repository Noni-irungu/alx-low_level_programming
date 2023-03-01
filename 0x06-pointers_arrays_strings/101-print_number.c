#include "main.h"

/**
 * print_number - a function that prints an integer
 * @n: int type number
 *
 * Return: Always 0
 */
void print_number(int n)
{
	long e; /* power of 10 */
	int w; /* boolean check */
	long num; /* convert int to long */

	num = n;
	/* negatives */
	if (num < 0)
	{
		num *= -1;
		_putchar('-');
	}

	/* count up */
	e = 1;
	w = 1;
	while (c)
	{
		if (num / (e * 10) > 0)
			e *= 10;
		else
			w = 0;
	}
	/* count down */
	while (num >= 0)
	{
		if (e == 1)
		{
			_putchar(num % 10 + '0');
			num = -1;
		}
		else
		{
			_putchar((num / e % 10) + '0');
			e /= 10;
		}
	}
}
