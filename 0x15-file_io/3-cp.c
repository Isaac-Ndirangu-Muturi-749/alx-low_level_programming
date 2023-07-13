#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
}

int main(int argc, char *argv[])
{
	int fileFrom, fileTo;
	ssize_t bytesRead, bytesWritten;
	char buffer[BUFFER_SIZE];

	/* Check if the number of arguments is correct */
	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		exit(97);
	}

	/* Open the source file in read-only mode */
	fileFrom = open(argv[1], O_RDONLY);
	if (fileFrom == -1)
	{
		print_error(argv[1]);
		exit(98);
	}

	/* Open the destination file in write-only mode, create it if it doesn't exist, and set permissions */
	fileTo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fileTo == -1)
	{
		print_error(argv[2]);
		exit(99);
	}

	/* Read data from the source file and write it to the destination file */
	while ((bytesRead = read(fileFrom, buffer, BUFFER_SIZE)) > 0)
	{
		bytesWritten = write(fileTo, buffer, bytesRead);
		if (bytesWritten == -1) {
			print_error(argv[2]);
			exit(99);
		}
	}

	/* Check for read errors */
	if (bytesRead == -1)
	{
		print_error(argv[1]);
		exit(98);
	}

	/* Close the source and destination file descriptors */
	if (close(fileFrom) == -1)
	{
		print_error("Can't close fd");
		exit(100);
	}

	if (close(fileTo) == -1)
	{
		print_error("Can't close fd");
		exit(100);
	}

	return (0);
}
