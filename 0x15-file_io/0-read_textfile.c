#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - the function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: text file that's being read
 * @letters: No. of letters to read
 * Return: w - actual No. of bytes read and printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t total = 0;
	char buffer[1024];
	ssize_t bytes_read;
	ssize_t fd;

	fd = open(filenmame, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	total = read(fd, buffer, letters);
	bytes_read = write(STDOUT_FILENO, buffer, total);

	free(buffer);
	close(fd);
	return (bytes_read);
}
