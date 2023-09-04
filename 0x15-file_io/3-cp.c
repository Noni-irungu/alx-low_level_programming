#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/**
 * main - a function that copies contents of a file to another file.
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 *
 * Description: if the argument count is incorrect - exit code 97.
 * if file_from doesn't exist or can't be read - exit code 98.
 * if file_to can't be created or written to - exit code 99.
 * if file_to or file_from can't be closed - exit code 100.
 */

int main(int argc, char **argv)
{
	int file0, file1, result0, result1;

	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (buff == NULL)
		return (0);

	file1 = open(argv[1], O_WRONLY);
	e_98(file1, buff, argv[1]);
	file0 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	e_99(file0, buff, argv[2]);

	do {
		result0 = read(file1, buff, BUFF_SIZE);

		if (result0 == 0)
			break;
		e_98(result0, buff, argv[1]);

		result1 = write(file0, buff, result0);
		e_99(result1, buff, argv[2]);
	}

	while (result1 >= BUFF_SIZE);
	result0 = close(file0);
	e_100(result0, buff);
	result0 = close(file1);
	e_100(result0, buff);
	free(buff);
	return (0);
}

/**
 * e_98 - checks for the error 98.
 * @file0: the value to check for the error.
 * @buff: the buffer
 * @argv: the argument
 */
void e_98(int file0, char *buff, char *argv)
{
	if (file0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
		free(buff);
		exit(98);
	}
}

/**
 * e_99 - checks for the error 99.
 * @file0: the value to check.
 * @buff: the buffer
 * @argv: argument
 */
void e_99(int file0, char *buff, char *argv)
{
	if (file0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
		free(buff);
		exit(99);
	}
}

/**
 * e_100 - checks for the error 100.
 * @file0: the value to check.
 * @buff: the buffer
 */
void e_100(int file0, char *buff)
{
	if (file0 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file0);
		free(buff);
		exit(100);
	}
}
