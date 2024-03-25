#include "main.h"

/**
 * _puts - prints a string, followed by a new line, stdout
 * @str: string to print, validate the character
 * Return: Always 0.
 */
void _puts(char *str)
{
	int u;

	for (u = 0; str[u] != '\0' ; u++)
	{
		_putchar(str[u]);
	}
	_putchar('\n');
}
