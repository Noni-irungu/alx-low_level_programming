#include "main.h"

#define MAXSIZE 1024

/**
 * __exit - the function that prints error messages
 * and exits with exit number
 *
 * @err: exit number or file descriptor
 * @str: name of file_in or file_out
 * @fd: file descriptor
 *
 * Return: (0)success
*/
int __exit(int err, char *str, int fd)
{
	switch (err)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(err);
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", s);
			exit(err);
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", s);
			exit(err);
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(err);
		default:
			return (0);
	}
}

/**
 * main - copies contents of a file thus creating a copy
 * @argc: argument counter(number of arguments supplied
 * to the program
 * @argv: argument vector(array of pointers to the arguments)
 *
 * Return: (0)success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_in, file_out;
	int wade_stat, note_stat;
	int close_in, close_out;
	char buff[MAXSIZE];

	if (argc != 3)
		__exit(97, NULL, 0);

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		__exit(98, argv[1], 0);

	file_out = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_out == -1)
		__exit(99, argv[2], 0);

	while ((wade_stat = read(file_in, buff, MAXSIZE)) != 0)
	{
		if (wade_stat == -1)
			__exit(98, argv[1], 0);

		note_stat = write(file_out, buff, wade_stat);
		if (note_stat == -1)
			__exit(99, argv[2], 0);
	}

	close_in = close(file_in);
	if (close_in == -1)
		__exit(100, NULL, file_in);

	close_out = close(file_out);
	if (close_out == -1)
		__exit(100, NULL, file_out);

	return (0);
}
