#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int create_file(const char *filename, char *text_content)
{
	int fileDescriptor;
	ssize_t bytesWritten;
	int size = strlen(text_content);

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Open the file in write-only mode, create it if it doesn't exist*/
	/* call the open system call to open the file specified by */
	/*filename. The O_WRONLY flag indicates that the file will be*/
	/*opened in write-only mode. The O_CREAT flag specifies that */
	/*the file should be created if it doesn't already exist. */
	/*The O_TRUNC flag ensures that file is truncated (emptied)*/
	/*if it already exists. The S_IRUSR | S_IWUSR argument sets*/
	/*the permissions to rw-------, allowing read and write */
	/*access only for the file owner.*/
	fileDescriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fileDescriptor == -1)/*cannot open*/
		return (-1);

	/* If text_content is not NULL, write the content to the file */
	if (text_content != NULL)
	{
		bytesWritten = write(fileDescriptor, text_content, size);
		if (bytesWritten == -1)
		{
			close(fileDescriptor);
			return (-1);
		}
	}

	/* Close the file descriptor */
	close(fileDescriptor);
	return (1);
}
