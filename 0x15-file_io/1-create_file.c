#include "main.h"

/**
 * create_file - Creates file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write to the file.
 *
 * Return: If function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int cx, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	cx = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(cx, text_content, len);

	if (cx == -1 || k == -1)
		return (-1);

	close(cx);

	return (1);
}

