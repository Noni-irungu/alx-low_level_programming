#include "main.h"

/**
 * binary_to_uint - a function that converts a binary
 * number to an unsigned integer.
 * @b: the binary string to convert.
 *
 * Return: a positive number converted from a binary.
 */
unsigned int binary_to_uint(const char *b)
{
	int g;
	unsigned int deci_value = 0;

	if (!b)
		return (0);

	for (g = 0; b[g]; g++)
	{
		if (b[g] < '0' || b[g] > '1')
			return (0);
		deci_value = 2 * deci_value + (b[g] - '0');
	}

	return (deci_value);
}
