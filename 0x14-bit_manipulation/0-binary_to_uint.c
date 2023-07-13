#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to the binary string
 *
 * Return: the converted number, or
 *         0 if there is an invalid character or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	/* Variable to store the converted number*/
	unsigned int result = 0;
	int i;

	/* Check if the string pointer is NULL, if so, return 0*/
	if (b == NULL)
		return (0);

	/* Iterate through each character of the string*/
	/*until the null terminator is encountered*/
	for (i = 0; b[i] != '\0'; i++)
	{
		/* Check if the current character is '0'*/
		if (b[i] == '0')
		{
			/* Shift the result left by 1 position*/
			/*(equivalent to multiplying by 2)*/
			result = result << 1;

		}

		/* Check if the current character is '1'*/
		else if (b[i] == '1')
		{
			/* Shift the result left by 1 position and*/
			/* set the least significant bit to 1*/
			/*(equivalent to multiplying by 2 and adding 1)*/
			result = (result << 1) | 1;
		}
		/* If the current character is neither '0' nor '1',*/
		/*return 0 (invalid character)*/
		else
			return (0);
	}

	/* Return the converted unsigned int value stored in 'result'*/
	return (result);
}
