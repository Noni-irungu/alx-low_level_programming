#include "main.h"
#include <stdlib.h>

/**
 * read_txtfile - reads textfile print to STDOUT
 * @filename: txtfile being read
 * @letters: No. of letters to be read
 * Return: w - actual No. of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_txtfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t = read(fd, buff, leters);
	w = write(STDOUT_FILENO, buff, t);
	free(buff);
	close(fd);
	return (w);
}
