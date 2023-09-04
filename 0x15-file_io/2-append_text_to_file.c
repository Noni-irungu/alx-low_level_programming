#include <string.h>
#include "main.h"

/**
 * append_text_to_file - Appends txt at the end of a file.
 * @filename: pointer to the name of the file.
 * @text_content: string to add to the end of the file.
 *
 * Return: If function fails or filename is NULL - -1.
 * If file does not exist the user lacks write permissions - -1.
 * Otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wri_te, length = 0;

	if (filename == NULL)
		return (-1);

/* opening the file in appended mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

/* writing text to the file */
	wri_te = write(fd, text_content, length);
	if (wri_te == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
