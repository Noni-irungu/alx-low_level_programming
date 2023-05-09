#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *manu_buff(char *doss);
void end_doss(int fd);

/**
 * manu_buff - allocates 1024 for buffer.
 * @doss: name of file buffer is storing characters
 *
 * Return: the pointer to newly-allocated buffer.
 */
char *manu_buff(char *doss)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", doss);
		exit(99);
	}

	return (buff);
}

/**
 * end_doss - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void end_doss(int fd)
{
	int e;

	e = close(fd);
	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - creates a copy of a file by copying
 * contents of a file to another file.
 * @argc: number of arguments supplied to the program(argument counter)
 * @argv: An array of pointers to the arguments(argument vector)
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
	int mid, via, r, w;
	char *buff;

	if (arc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = manu_buff(argv[2]);
	mid = open(argv[1], O_RDONLY);
	r = read(mid, buff, 1024);
	via = open(arv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (mid == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(via, buff, r);
		if (via == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(mid, buff, 1024);
		via = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buff);
	end_doss(mid);
	end_doss(via);

	return (0);
}
