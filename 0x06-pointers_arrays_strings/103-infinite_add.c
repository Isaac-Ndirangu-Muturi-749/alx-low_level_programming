#include "main.h"

/**
 * rev_string - Reverse an array of characters.
 * @n: Pointer to the array.
 */
void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	/* Calculate the length of the string*/
	while (*(n + i) != '\0')
	{
		i++;
	}
	i--;

	// Swap characters from the beginning and end of the string
	for (j = 0; j < i; j++, i--)
	{
		temp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = temp;
	}
}

/**
 * infinite_add - Add two numbers together.
 * @n1: Text representation of the first number to add.
 * @n2: Text representation of the second number to add.
 * @r: Pointer to the buffer to store the result.
 * @size_r: Size of the buffer.
 *
 * Return: Pointer to the result stored in the buffer, or 0 if the result
 * cannot be stored in the buffer.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, i = 0, j = 0, digits = 0;
	int val1 = 0, val2 = 0, temp_tot = 0;

	/*Calculate the lengths of n1 and n2*/
	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;

	/*Check if the result can be stored in the buffer*/
	if (j >= size_r || i >= size_r)
		return (0);

	/*Perform addition from right to left*/
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		/*Get the value of the current digit in n1 and n2*/
		if (i < 0)
			val1 = 0;
		else
			val1 = *(n1 + i) - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = *(n2 + j) - '0';

		/*Calculate the sum of the current digits*/
		temp_tot = val1 + val2 + overflow;

		/*Check for overflow*/
		if (temp_tot >= 10)
			overflow = 1;
		else
			overflow = 0;

		/*Check if the result exceeds the buffer size*/
		if (digits >= (size_r - 1))
			return (0);

		/*Store the current digit in the result buffer*/
		*(r + digits) = (temp_tot % 10) + '0';
		digits++;
		j--;
		i--;
	}

	/*Null-terminate the result buffer*/
	if (digits == size_r)
		return (0);
	*(r + digits) = '\0';

	/*Reverse the result string*/
	rev_string(r);

	return (r);
}
