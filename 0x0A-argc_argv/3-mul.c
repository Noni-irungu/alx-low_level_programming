#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - a program that multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int x, y, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	result = x * y;
	printf("%d\n", result);
	return (0);
}

