#include <stdlib.h>
#include <stdio.h>

/**
 * *malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to the allocated memory
 *         terminates the process with status value 98 on failure
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	/* Allocate memory using malloc */
	ptr = malloc(b);

	/* Check if malloc failed (returned NULL) */
	if (ptr == NULL)
	{
		/* Print error message to stderr */
		fprintf(stderr, "Error: malloc failed\n");
		/* Terminate the process with status value 98 */
		exit(98);
	}

	/* Return the allocated pointer */
	return (ptr);
}
