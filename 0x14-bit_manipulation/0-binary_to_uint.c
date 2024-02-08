#include "main.h"

/**
 * binary_to_unsignint - a function that converts a binary
 * number to an unsigned integer.
 * @x: the binary string to convert.
 *
 * Return: a positive number converted from a binary.
 */
unsigned int binary_to_unsignint(const char *x)
{
	int g;
	unsigned int deci_value = 0;

	if (!x)
		return (0);

	for (g = 0; x[g]; g++)
	{
		if (x[g] < '0' || x[g] > '1')
			return (0);
		deci_value = 2 * deci_value + (x[g] - '0');
	}

	return (deci_value);
}
