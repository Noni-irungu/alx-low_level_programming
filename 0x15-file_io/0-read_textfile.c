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
	if (filename == NULL)
	{
		return (0);
	}
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}
	ssize_t total = 0;
	char buffer[1024];
	ssize_t bytes_read;

	while (total < letters && (bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
		{
			close(fd);
			return (0);
		}
		total += bytes_read;
	}
	close(fd);
	return (total);
}
