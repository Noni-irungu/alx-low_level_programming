#include "main.h"

/**
 * append_text_to_file - the function that appends text
 * at the end of a file.
 * @filename: the pointer to the name of the file to add data to
 * @text_content: string to add to the end of the file.
 *
 * Return: If function fails or filename is NULL or
 * file does not exist the user lacks write permissions (-1).
 * Otherwise(1).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int doss, prog_status, wrds = 0;

	if (filename == NULL)
		return (-1);

	doss = open(filename, O_APPEND | O_WRONLY);
	if (doss == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[wrds] != '\0')
			wrds++;

		prog_status = write(doss, text_content, wrds);
		if (prog_status == -1)
			return (-1);
	}

	close(doss);
	return (1);
}
