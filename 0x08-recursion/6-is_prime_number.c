#include "main.h"
#include <math.h>

/**
 * is_prime_number - a function that returns 1
 * if the integer is a prime number, otherwise return 0
 * @n: input
 *
 * Return: Always 0
 */
int is_prime_number(int n)
{
	if (n <= 2)
	{
		return (0);
	}

	if (n == 2 || n == 3)
	{
		return (1);
	}

	if (n % 2 == 0 || n % 3 == 0)
	{
		return (0);
	}
}
