#include "main.h"
#include <stdio.h>
/**
 * print_alphabet_x10 - a function that prints 10 times the
 * alphabet in lowercase
 * followed by a newline
 */

void print_alphabet_x10(void)
{
	char c;
	int i = 0;

	while (i <= 10)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
