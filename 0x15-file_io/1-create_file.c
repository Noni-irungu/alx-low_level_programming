#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: a pointer to the name of the file to be created.
 * @text_content: a pointer to a string to write to the file.
 * Return: -1 if filename is NULL and on failure, otherwise (1) on success.
 *
 */

int create_file(const char *filename, char *text_content)
{
	int cf, temp, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length])
			length++;
	}

	cf = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	temp = write(cf, text_content, length);


	if (cf == -1 || temp == -1)
		return (-1);

	close(cf);

	return (1);
}
