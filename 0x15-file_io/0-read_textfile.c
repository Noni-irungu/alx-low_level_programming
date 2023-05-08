#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - the function that reads a text file
 * and prints it to standard output.
 * @filename: text file that's being read
 * @letters: No. of letters to read
 * Return: o/w - actual No. of bytes read and printed
 * (0) when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t o, r, w;

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buff, letters);
	w = write(STDOUT_FILENO, buff, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buff);
		close(o);
		return (w);
}
