#include "main.h"

/**
  * binary_to_uint - Converts binary number to an unsigned int
  * @b: the binary string to converts
  *
  * Return: positve number converted from a binary
  */
unsigned int binary_to_uint(const char *b)
{
	int y;
	unsigned int dec_valu = 0;

	if (!b)
		return (0);

	for (y = 0; b[y]; y++)
	{
		if (b[y] < '0' || b[y] > '1')
			return (0);
		dec_valu = 2 * dec_valu + (b[y] - '0');
	}

	return (dec_valu);
}
