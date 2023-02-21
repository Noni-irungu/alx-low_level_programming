#include "main.h"

/**
 * print_alphabet - function that prints the alphabet in lowercase
 * Return:0
 */

void print_alphabet(void)
{
	char lett = 'a';

	while (lett <= 'z')
	{
		_putchar(lett);
		lett++;
	}
	_putchar('\n');
}
