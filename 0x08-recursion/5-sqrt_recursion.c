#include "main.h"
#include <math.h>


/**
 * _sqrt_recursion - a function that returns the natural
 * square root of a number
 * @n: input
 *
 * Return: Success(0)
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		int result = (n + 1) / 2;
		int prev_result = 0;

		while (result != prev_result)
		{
			prev_result = result;
			result = (result + n / result) / 2;
		}
		return (result);
	}
}
