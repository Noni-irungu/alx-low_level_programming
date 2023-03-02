#include "main.h"

/**
 * cap_string - Capitilization of all words of a string
 * @str: The string to be capitilized
 *
 * Return: A pointer to the changed string.
 */
char *cap_string(char *str)
{
	int k = 0;

	while (s[k] != '\0')
	{
		if (s[0] <= 122 && s[0] >= 97)
		{
			s[0] = s[0] - 32;
		}
		if (s[k] == 32 || s[k] == 46 || s[k] == '\t' ||
			s[k] == '\n' || s[k] == 44 || s[k] == 59 ||
				s[k] == '!' || s[k] == '?' || s[k] == '(' ||
				s[k] == ')' || s[k] == '{' || s[k] == '}')
		{
			if (s[k + 1] <= 122 && s[k + 1] >= 97)
			{
				s[k + 1] = s[k + 1] - 32;
			}
		}
	k++;
	}
	return (s);
}
