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
	int num_coins = 0;

	num_coins += cents / 25;
	cents %= 25;
	num_coins += cents / 10;
	cents %= 10;
	num_coins += cents / 5;
	cents %= 5;
	num_coins += cents / 2;
	cents %= 2;
	num_coins += cents;

	/*Print the result and return*/
	printf("%d\n", num_coins);
	return (0);
}
