#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and writes it to POSIX stdout.
 * @filename: Head pointer to  file.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t openFile, readFile, writeFile;
	char *fileBuffer;

	if (filename == NULL)
		return (0);

	fileBuffer = malloc(sizeof(char) * letters);
	if (fileBuffer == NULL)
		return (0);

	openFile = open(filename, O_RDONLY);
	readFile = read(openFile, fileBuffer, letters);
	writeFile = write(STDOUT_FILENO, fileBuffer, readFile);

	if (writeFile == -1 || writeFile != readFile ||
			openFile == -1 || readFile == -1)
	{
		free(fileBuffer);
		return (0);
	}

	free(fileBuffer);
	close(openFile);

	return (writeFile);
}
