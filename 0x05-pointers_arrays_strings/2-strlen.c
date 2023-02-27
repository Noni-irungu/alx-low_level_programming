#include "main.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: s is a character (string)
 * Return: value is t (length)
 */
int _strlen(char *s)
{
	int t;

	for (t = 0; s[t] != '\0'; t++)
	{
		s++;
	}
	return (t);
}
