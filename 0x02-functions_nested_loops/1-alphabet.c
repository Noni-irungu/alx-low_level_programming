#include "main.h"

/**
 * print_alphabet - function that prints the alphabet in lowercase
 */

void print_alphabet(void)
{
	char lett;

	for (lett = 'a'; lett <= 'z'; lett++)
		_putchar(lett);

	_putchar('\n');
}
