#include "main.h"

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b: string containing binary number
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
		return (0);

	unsigned int value = 0;

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

	value = value * 2 + (*b - '0');
	b++;
	}

	return (value);
}
