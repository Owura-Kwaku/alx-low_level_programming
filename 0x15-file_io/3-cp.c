#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Stes 1024 bytes of memory for a buffer.
 * @file: Stored buffer file name.
 *
 * Return: new buffer.
 */

char *create_buffer(char *file)
{
	char *fileBuffer;

	fileBuffer = malloc(sizeof(char) * 1024);
	if (fileBuffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (fileBuffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */

void close_file(int fd)
{
	int closeFile;

	closeFile = close(fd);
	if (closeFile == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int openSource, openDestination, readFile, writeFile;
	char *fileBuffer;


	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}


	fileBuffer = create_buffer(argv[2]);
	openSource = open(argv[1], O_RDONLY);
	readFile = read(openSource, fileBuffer, 1024);
	openDestination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);


	do {
		if (openSource == -1 || readFile == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(fileBuffer);
			exit(98);
		}


		writeFile = write(openDestination, fileBuffer, readFile);
		if (openDestination == -1 || writeFile == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(fileBuffer);
			exit(99);
		}


		readFile = read(openSource, fileBuffer, 1024);
		openDestination = open(argv[2], O_WRONLY | O_APPEND);


	} while (readFile > 0);


	free(fileBuffer);
	close_file(openSource);
	close_file(openDestination);


	return (0);
}
