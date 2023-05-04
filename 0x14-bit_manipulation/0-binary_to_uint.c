#include "main.h"

/**
 * binary_to_uint - the function converts binary number to an
 * unsigned int
 * @b: the string to be converted
 *
 * Return: the converted number or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int z;
	unsigned int de_val = 0;

	if (!b)
		return (0);

	for (z = 0; b[z]; z++)
	{
		if (b[z] < '0' || b[z] > '1')
			return (0);
		de_val = 2 * de_val + (b[z] - '0');
	}

	return (de_val);
}
