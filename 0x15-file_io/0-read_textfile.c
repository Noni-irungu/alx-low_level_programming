#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads text file print to STDOUT.
 * @filename: text file being read
 * @letters: No. of letters to be read
 * Return: w - actual NO. of bytes read and printed
 * 0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;

	ssize_t re_ad, wri_te;

	char *buff;

	if (filename == NULL)
		return (0);

/* opening a file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

/* creating a buffer to store the characters */
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

/* reading a file */
	re_ad = read(fd, buff, letters);
	if (re_ad == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

/* writing/printing out a file */
	wri_te = write(STDOUT_FILENO, buff, re_ad);
	if (wri_te == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}

	close(fd);
	return (re_ad);
}
