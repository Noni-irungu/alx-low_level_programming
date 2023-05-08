#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - the function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: text file that's being read
 * @letters: No. of letters to read
 * Return: w - actual No. of bytes read and printed
 * (0)failure or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t t;
	char *buffer;
	ssize_t w;
	ssize_t fd;

	fd = open(filenmame, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	t = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(fd);
	return (w);
}
