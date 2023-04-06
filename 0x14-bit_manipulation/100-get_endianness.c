#include "main.h"

/**
 * get_endianness - checks if machine is little or big endian
 * Return: 0 if big, 1 if little
 */
int get_endianness(void)
{
	unsigned int p = 1;
	char *c = (char *) &p;

	return (*c);
}

