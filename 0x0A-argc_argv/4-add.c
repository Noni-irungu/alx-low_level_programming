#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - a program that adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	/*if no arguments are passed, print 0 and return*/
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/*Loop through each argument*/
	for (int i = 1; i < argc; i++)
	{
		/*Check that each character in the argument is a digit*/
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		/*Convert the argument to an integer and add to the sum if positive*/
		int num = atoi(argv[i]);

		if (num > 0)
		{
			sum += num;
		}
	}

	/*Print the sum and return*/
	printf("%d\n", sum);
	return (0);
}
