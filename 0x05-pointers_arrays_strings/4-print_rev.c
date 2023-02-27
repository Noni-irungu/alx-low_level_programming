#include "main.h"

/**
 * print_rev - print reverse characters(imprime en reversa)
 * @s: string validate the character
 * Return: 0
 */
void print_rev(char *s)
{
	int d = 0;

	while (s[d] != '\0')
	{
		d++;
	}
	d--;
	for (; d >= 0; d--)
	{
		_putchar(s[d]);
	}
	_putchar('\n');
}
