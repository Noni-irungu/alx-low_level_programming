#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: a pointer to the name of the file to be created.
 * @text_content: a pointer to a string to write to the file.
 * Return: (-1) if function fails, otherwise (1).
 *
 */

int create_file(const char *filename, char *text_content)
{
	int cf, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	cf = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(cf, text_content, len);

	if (cf == -1 || k == -1)
		return (-1);

	close(cf);

	return (1);
}
