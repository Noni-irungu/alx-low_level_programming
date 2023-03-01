#include "mainh"

/**
 * _strcmp - a function that compares string values
 * @s1: input value
 * @s2: input value
 *
 * Return: Always 0
 */
int _strcmp(char *s1, char *s2)
{
	int k;

	while ((s1[k] == s2[k]) && (s1[k] != '\0'))
	{
		k++;
	}
	return (s1[k] - s2[k]);
}
