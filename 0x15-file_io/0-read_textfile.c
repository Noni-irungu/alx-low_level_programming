#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads textfile print to STDOUT
 * @filename: textfile being read
 * @letters: No. of letters to be read
 * Return: w - actual No. of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffe;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffe = malloc(sizeof(char) * letters);
	t = read(fd, buffe, leters);
	w = write(STDOUT_FILENO, buffe, t);
	free(buffe);
	close(fd);
	return (w);
}
