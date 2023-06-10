#include "main.h"

/**
 * _memset - Fills memory with a constant byte.
 * @s: Pointer to the memory area to be filled.
 * @b: The constant byte to fill the memory with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	/* Convert the constant byte to unsigned char */
	unsigned char byte = (unsigned char)b;

	/* Iterate through each byte in the memory area */
	while (n > 0)
	{
		/* Fill the byte with the constant value */
		*s = byte;

		/* Move to the next byte in the memory area */
		s++;
		n--;
	}

	/* Return the pointer to the memory area */
	return (s);
}
