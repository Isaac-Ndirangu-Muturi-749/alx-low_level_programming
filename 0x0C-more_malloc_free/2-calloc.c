#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and initializes it with zero
 * @nmemb: number of elements in the array
 * @size: size of each element in bytes
 *
 * Return: pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;

	/* Check if nmemb or size is 0 */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calculate the total size required */
	total_size = nmemb * size;

	/* Allocate memory using malloc */
	ptr = malloc(total_size);

	/* Check if malloc failed (returned NULL) */
	if (ptr == NULL)
		return (NULL);

	/* Set the allocated memory to zero using memset */
	memset(ptr, 0, total_size);

	/* Return the pointer to the allocated memory */
	return (ptr);
}
