#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: a pinter ro the name of the file.
 * @text_content: a string to add to the end of the file.
 *
 * Return: if function fails of filename is NULL (-1), otherwise (1).
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	k = write(o, text_content, len);

	if (o == -1 || k == -1)
		return (-1);

	close(o);

	return (1);
}
