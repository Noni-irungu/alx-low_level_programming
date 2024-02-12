#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fl);

/**
 * create_buffer - a function that allocates 1024 bytes for a buffer.
 * @file: the name of the file the buffer is storing chars for.
 *
 * Return: a pointer to the newly-allocated buffer.
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - a function that closes the file descriptors.
 * @fl: the file descriptor to be closed.
 */

void close_file(int fl)
{
	int f;

	f = close(fl);

	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fl);
		exit(100);
	}
}

/**
 * main - a function that copies contents of a file to another file.
 * @argc: the number of arguments supplied to the program.
 * @argv: an array of pointers to the arguments.
 *
 * Return: (0) on success.
 *
 * Description:
 * if the argument count is incorrect, it exits code 97.
 * if file_from does not exist or cannot be read, it exits code 98.
 * if file_to cannot be created or written to, it exits code 99.
 * if file_to or file_from cannot be closed, it exits code 100.
 */

int main(int argc, char *argv[])
{
	int frm, to, re, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	frm = open(argv[1], O_RDONLY);
	re = read(frm, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || re == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(to, buffer, re);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		re = read(frm, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (re > 0);

	free(buffer);
	close_file(frm);
	close_file(to);

	return (0);
}
