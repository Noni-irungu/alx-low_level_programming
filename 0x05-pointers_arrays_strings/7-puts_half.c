#include "main.h"

/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int v = 0, n;


	while (str[v] != '\0')
	{
		v++;
	}
	if (v % 2 == 1)
	{
		n = (v + 1) / 2;
		while (str[n] != '\0')
		{
		_putchar(str[n]);
		n++;
		}
	}
	else
	{
		n = (v / 2);
		while (str[n] != '\0')
		{
			_putchar(str[n]);
			n++;
		}
	}
	_putchar('\n');
}
