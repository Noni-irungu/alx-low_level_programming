#include "main.h"

/**
  * binary_to_uint - Converts a binary number to an unsigned int
  * @b: The binary string to converts
  *
  * Return: The positive number converted from a binary
  */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int len = strlen(b);

	if (b == NULL)
	{
	return (0);
	}

	for (int i = 0; i < len; i++)
	{
		if (b[i] == '0')
		{
			result = result * 2;
		}
		else if (b[i] == '1')
		{
			result = result * 2 + 1;
		}
		else
		{
		return (0);
		}
	}
	return (result);
}
