#include "main.h"
#include <stdio.h>
/**
 * print_alphabet_x10 - a function that prints 10 times the
 * alphabet in lowercase
 * followed by a newline
 */

void print_alphabet_x10(void)
{
	int count = 0;
	char lettr;

	while (count++ <= 9)
	{
		for (lettr = 'a'; lettr <= 'z'; lettr++)
			_putchar(lettr);
	}
	_putchar('\n');
}
