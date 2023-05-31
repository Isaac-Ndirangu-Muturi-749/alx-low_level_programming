#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */
void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	/* Find the length of the string */
	while (*(n + i) != '\0')
	{
		i++;
	}
	i--;

	/* Swap characters from the beginning and end of the string */
	for (j = 0; j < i; j++, i--)
	{
		temp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = temp;
	}
}

/**
 * infinite_add - add 2 numbers together
 * @n1: text representation of 1st number to add
 * @n2: text representation of 2nd number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 * Return: pointer to calling function
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, i = 0, j = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_tot = 0;

	/* Find the lengths of the input strings */
	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j--;
	i--;
	j--;

	/* Check if input lengths exceed buffer size */
	if (j >= size_r || i >= size_r)
		return (0);

	/* Perform addition digit by digit */
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		/* Get the current digits to be added */
		if (i < 0)
			val1 = 0;
		else
			val1 = *(n1 + i) - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = *(n2 + j) - '0';

		temp_tot = val1 + val2 + overflow; /* Add digits and overflow */

		/* Check if there is an overflow */
		if (temp_tot >= 10)
			overflow = 1;
		else
			overflow = 0;

		/* Check if result exceeds buffer size */
		if (digits >= (size_r - 1))
			return (0);

		/* Store the digit in the result buffer */
		*(r + digits) = (temp_tot % 10) + '0';
		digits++;
		j--;
		i--;
	}

	/* Check if the result fills the buffer completely */
	if (digits == size_r)
		return (0);

	*(r + digits) = '\0'; /* Add null terminator to the result string */
	rev_string(r); /* Reverse the result string */
	return (r); /* Return the result string */
}
