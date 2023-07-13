#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates 1024 bytes for a buffer
 * @filename: The name of the file
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *filename)
{
	char *buffer;

	/* Allocate memory for the buffer */
	buffer = malloc(sizeof(char) * 1024);

	/* Check if memory allocation failed */
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}



/**
 * close_file - Closes file descriptors.
 * @file_descriptor: The file descriptor to be closed.
 */
void close_file(int file_descriptor)
{
	int c;

	/* Close the file descriptor */
	c = close(file_descriptor);

	/* Check if closing the file descriptor failed */
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}


/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *             If file_from does not exist or cannot be read - exit code 98.
 *             If file_to cannot be created or written to - exit code 99.
 *             If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_file, destination_file,  bytesread, byteswritten;
	char *buffer;

	/* Check if the argument count is correct */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Create the buffer */
	buffer = create_buffer(argv[2]);

	/* Open the source file for reading */
	source_file = open(argv[1], O_RDONLY);

	/* Read from the source file into the buffer */
	bytesread = read(source_file, buffer, 1024);

	/* Open the destination file for writing */
	destination_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	/* Loop until all data is read and written */
	do {
		/* Check if reading from the source file failed */
		if (source_file == -1 || bytesread == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		/* Write the buffer contents to the destination file */
		w = write(to, buffer, r);

		/* Check if writing to the destination file failed */
		if (destination_file == -1 || byteswritten == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		/* Read from the source file into the buffer */
		byteswritten = read(source_file, buffer, 1024);

		/* Open the destination file in append mode */
		destination_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytesread > 0);

	/* Free the buffer memory */
	free(buffer);

	/* Close the file descriptors */
	close_file(source_file);
	close_file(destination_file);

	return (0);
}
