#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: Head pointer to file-name.
 * @text_content: is the NULL terminated string to add at the end of the
 * file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int openFile, writeFile, length = 0;


	if (filename == NULL)
		return (-1);


	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}


	openFile = open(filename, O_WRONLY | O_APPEND);
	writeFile = write(openFile, text_content, length);


	if (openFile == -1 || writeFile == -1)
		return (-1);


	close(openFile);


	return (1);
}
