#include "main.h"

/**
 * rev_string - Reverses a string, prints reverse characters
 * @s: input string
 * Return: String in reverse
 */
void rev_string(char *s)
{
	int g = 0, x = 0, Aux;


	while (s[g] != '\0')
	{
		g++;
	}
	g--;
	while (g > x)
	{
		Aux = s[g];
		s[g--] = s[x];
		s[x++] = Aux;
	}
}
