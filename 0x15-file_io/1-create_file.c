#include "main.h"

/**
 * create_file - A function that creates a file
 * @text_content: is a NULL terminated string to write to the file
 * @filename: is the name of the file to create
 *
 * Return: 1 (success), -1 (failure)
 */

int create_file(const char *filename, char *text_content)
{
	int openFile, writeFile, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	openFile = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writeFile = write(openFile, text_content, length);

	if (openFile == -1 || writeFile == -1)
		return (-1);

	close(openFile);

	return (1);
}
