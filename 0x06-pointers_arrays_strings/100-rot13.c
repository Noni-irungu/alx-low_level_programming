#include "main.h"
#include <stdio.h>

/**
 * rot13 - encoder rot13
 * @str: s is the array
 *
 * Return: Always 0
 */
char *rot13(char *str)
{
	int w = 0, z;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s1[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (; str[w] != '\0'; z++)
	{
		for (z = 0; z <= 51; z++)
		{
			if (s[z] == str[w])
			{
				str[w] = s1[z];
			}
		}
	}
	return (str);
}

