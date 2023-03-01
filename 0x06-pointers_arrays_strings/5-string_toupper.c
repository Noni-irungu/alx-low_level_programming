#include "main.h"

/**
 * string_toupper - a function that changes all lowercase
 * to uppercase
 * @n: pointer
 *
 * Return: n
 */
char *string_toupper(char *n)
{
	int y = 0;

	while (s[y] != '\0')
	{
		if ((s[y] >= 97) && (s[y] <= 122))
		{
			s[y] = s[y] - 32;
		}
	y++;
	}
	return (s);
}

