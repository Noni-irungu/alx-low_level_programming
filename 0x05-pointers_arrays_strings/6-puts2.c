#include "main.h"

/**
 * puts2 - a function should print only one character out of two
 * starting with the first one
 * @str: input, validate the character
 * Return: print
 */
void puts2(char *str)
{
	int b = 0;

	while (str[b] != '\0')
	{
		if (b % 2 == 0)
		{
		_putchar(str[b]);
		}
		b++;
	}
	_putchar('\n');
}
