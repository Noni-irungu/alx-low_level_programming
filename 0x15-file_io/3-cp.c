#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if file can open.
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector(array of arguments)
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - the function that copies content
 * of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: double pointer to the arguments
 * Return: always 0(success)
 */
int main(argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t nocharas, nwr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	error_file(file_from, file_to, argv);

	nocharas = 1024;
	while (nocharas == 1024)
	{
		nocharas = read(file_from, buffer, 1024);
		if (nocharas == -1)
			error_file(-1, 0, argv);
		nwr = write(file_to, buffer, nocharas);
		if (nwr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
