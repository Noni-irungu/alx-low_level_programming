#include "main.h"
#include <math.h>

/**
 * _pow_recursion - a function that returns the value of x
 * raised to the power of y
 * @x: input
 * @y: input
 *
 * Return: Always 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else if (y % 2 == 0)
	{
		int temp = _pow_recursion(x, y / 2);

		return (temp * temp);
	}
	else
	{
		int temp = _pow_recursion(x, (y - 1) / 2);

		return (x * temp * temp);
	}
}
