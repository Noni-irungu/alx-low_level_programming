#include "main.h"

/**
  * binary_to_uint - Converts a binary number to an unsigned int
  * @b: The binary string to converts
  *
  * Return: The positive number converted from a binary
  */
unsigned int binary_to_uint(const char *b)
{
	int len = strlen(b);
	unsigned int decimal = 0;
	int i;

	for (i = 0; i < len; i++)
	{
		if (b[i] == '1')
		{
			decimal += pow(2, len - i - 1);
		}
		else if (b[i] != '0')
		{
			return (0);
		}
	}
	return (decimal);
}
