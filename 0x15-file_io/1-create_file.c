#include "main.h"

/**
 * create_file - a function that creates file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write to the file.
 *
 * Return: If function fails - -1.
 * Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int folder;
	int ans;
	int countno;

	ans = 1;
	countno = 0;

	if (filename == NULL)
		return (-1);

	folder = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (folder == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[countno])
			countno++;
		ans = write(folder, text_content, countno);
	}

	if (ans == -1)
		return (-1);

	close(folder);
	return (1);
}
