#include "main.h"

/**
 * print_most_numbers - checks for checks for a digit (0 through 9)
 *
 * Return: Always 0.
 */

void print_most_numbers(void)
{
	int k;

	for (k = 48; k < 58; k++)
	{
		if (k != 50)
		{
			if (k != 52)
			{
				_putchar(k);
			}
		}
	}
	_putchar('\n');
}
