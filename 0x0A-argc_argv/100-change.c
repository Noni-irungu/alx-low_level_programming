#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Prints the minimum number of coins to make
 * change for an amount of money
 * @argc: number of atguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1 (Error)
 */

int  main(int argc, char *argv[])
{
	/*Check that exactly one argument is passed*/
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/*Convert the argument to an integer*/
	int cents = atoi(argv[1]);

	/*Check that the argument is non-negative*/
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/*Calculate the minimum number of coins needed*/
	int coins = 0;
	int remaining_cents = cents;

	coins += remaining_cents / 25;
	remaining_cents %= 25;

	coins += remaining_cents / 10;
	remaining_cents %= 10;

	coins += remaining_cents / 5;
	remaining_cents %= 5;

	coins += remaining_cents / 2;
	remaining_cents %= 2;

	coins += remaining_cents;

	/*Print the result and return*/
	printf("%d\n", coins);
	return (0);
}
