#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - the function that reads a text file
 * and prints it to standard output.
 * @filename: text file that's being read
 * @letters: No. of letters to read
 * Return: w - actual No. of bytes read and printed
 * (0) when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t = read(fd, buff, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buff);
	close(o);
	return (w);
}
