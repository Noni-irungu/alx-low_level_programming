#include "main.h"

/**
 * create_file - the function that creates a file.
 * @filename: the pointer to file to create.
 * @text_content: the pointer to string to write to the file.
 *
 * Return: If on failure(-1).
 *         Otherwise(1).
 */
int create_file(const char *filename, char *text_content)
{
	int doss, note_status, wrds = 0;

	if (filename == NULL)
		return (-1);

	doss = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (doss == -1)
		return (-1);

	if (txt_cotnt)
	{
		while (txt_cotnt[wrds] != '\0')
			wrds++;

		note_status = write(doss, txt_cotnt, wrds);
		if (note_status == -1)
			return (-1);
	}

	close(doss);
	return (1);
}

