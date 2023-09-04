#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buff(char *folder);
void close_folder(int fd);


/**
 * create_buff - allocates 1024 bytes for a buffer.
 * @folder: name of file the buffer is storing characters for
 *
 * Return: pointer
 */
char *create_buff(char *folder)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", folder);
		exit(99);
	}

	return (buff);
}

/**
 * close_folder - a function that closes file descriptors.
 * @fd: the file descriptor to be closed
 */
void close_folder(int fd)
{
	int t;

	t = close(fd);

	if (t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

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

int main(int argc, char *argv[])
{
	int prev_ious, cur_rent, re_ad, wri_te;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buff(argv[2]);
	prev_ious = open(argv[1], O_RDONLY);
	re_ad = read(prev_ious, buff, 1024);
	cur_rent = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (prev_ious == -1 || re_ad == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wri_te = write(cur_rent, buff, re_ad);
		if (cur_rent == -1 || wri_te == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		re_ad = read(prev_ious, buff, 1024);
		cur_rent = open(argv[2], O_WRONLY | O_APPEND);

	} while (re_ad > 0);

	free(buff);
	close_folder(prev_ious);
	close_folder(cur_rent);

	return (0);
}
