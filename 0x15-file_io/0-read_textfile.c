#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - the function that reads a text file
 * and prints it to standard output.
 * @filename: is the text file thats is being read
 * @letters: number of letters to read and print from file
 *
 * Return: 0 if it fails or actual number of letters it could
 *         read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int doss;
	ssize_t read_chec, worcnt;
	char *buff;

	if (filename == NULL)
		return (0);

	doss = open(filename, O_RDONLY);

	if (doss == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		free(buff);
		return (0);
	}

	read_chec = read(doss, buff, letters);
	if (read_chec == -1)
		return (0);

	worcnt = write(STDOUT_FILENO, buff, read_chec);
	if (worcnt == -1 || read_chec != worcnt)
		return (0);

	free(buff);

	close(doss);

	return (worcnt);
}
