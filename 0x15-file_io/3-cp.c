#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_bufr(char *file);
void close_file(int cx);

/**
 * create_bufr - Allocates 1024 bytes for a buffer.
 * @file: name of the file buffer is storing chars for.
 *
 * Return: pointer to the newly-allocated buffer.
 */
char *create_bufr(char *file)
{
	char *bufr;

	bufr = malloc(sizeof(char) * 1024);

	if (bufr == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bufr);
}

/**
 * close_file - Closes file descriptors.
 * @cx: file descriptor to be closed.
 */
void close_file(int cx)
{
	int q;

	q = close(cx);

	if (q == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close cx %d\n", cx);
		exit(100);
	}
}

/**
 * main - Copies contents of a file to another file.
 * @argc: No. of arguments supplied to the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, t, k;
	char *bufr;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bufr = create_bufr(argv[2]);
	from = open(argv[1], O_RDONLY);
	t = read(from, bufr, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || t == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bufr);
			exit(98);
		}

		k = write(to, bufr, t);
		if (to == -1 || k == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(bufr);
			exit(99);
		}

		t = read(from, bufr, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (t > 0);

	free(bufr);
	close_file(from);
	close_file(to);

	return (0);
}
