#include "main.h"

/**
 * print_diagonal - it draws a diagonal line
 * on the terminal
 * @n: number of times the character \ should be printed
 */

void print_diagonal(int n)
{
	int g, h;

	if (n > 0)
	{
		for (g = 1; g <= n; g++)
		{
			for (h = 1; h <= n; h++)
			{
				if (g == h)
				{
					_putchar(92);
					break;
				}
				_putchar(' ');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
