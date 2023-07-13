#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to the string containing the binary number.
 *
 * Return: The converted unsigned int number, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int i;

	if (b == NULL) /* Check if the input string is NULL */
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		/* Check if the character is not '0' or '1' */
		if (b[i] != '0' && b[i] != '1')
			return (0);
		/*multiplying the current value by 2 (left shift by 1) and*/
		/*adding the decimal value of the binary digit to it.*/
		/* Left shift the result by 1 and add the binary digit to it */
		result = (result << 1) + (b[i] - '0');
	}

	return (result); /* Return the converted unsigned int number */
}
