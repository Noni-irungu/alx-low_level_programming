#include "main.h"

/**
 * main - the function that copies content
 * of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: double pointer to the arguments
 * Return: the actual number of letters it could read and print
 */
int main(argc, char **argv)
{
	int f1, f2, j;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
	{
		 dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		 exit(98);
	}
	f2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	while ((j = read(f1, buffer, 1024)) > 0)
	{
		if (write(f2, buffer, j) != j || f2 == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(f1) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f1);
		exit(100);
	}
	if (close(f2) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f2);
		exit(100);
	}
	return (0);
}
