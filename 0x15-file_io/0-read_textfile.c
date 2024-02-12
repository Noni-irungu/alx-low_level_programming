#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads text files printing it to STDOUT.
 * @filename: the text file that is being read.
 * @letters: the number of letters to be read.
 * Return: w - actual number of letters it could read and print
 * 0 - if file ca not be opened or read, if write fails or doesn not
 * write the expected amount of bytes and if filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd, w, temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	temp = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, temp);

	free(buffer);
	close(fd);
	return (w);
}
