#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * multiply_numbers - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 *
 * Description: This function multiplies two
 * positive numbers and prints the result.
 *
 * It performs the multiplication using an
 * algorithm similar to long multiplication.
 *
 * Return: None
 */
void multiply_numbers(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry;
	int *result, product, num1_digit, num2_digit;
	/* Calculate the lengths of the input numbers */
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;
	/* Allocate memory to store the result */
	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
	{
		exit(98);
	}
	/* Initialize the result array */
	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)/* Perform the multiplication */
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			num1_digit = num1[i] - '0';
			num2_digit = num2[j] - '0';
			product = num1_digit * num2_digit + result[i + j + 1] + carry;

			carry = product / 10;
			result[i + j + 1] = product % 10;
		}

		result[i] += carry;
	}
	/* Skip leading zeros in the result */
	i = 0;
	while (i < len1 + len2 - 1 && result[i] == 0)
		i++;
	/* Print the result */
	while (i < len1 + len2)
		printf("%d", result[i++]);
	printf("\n");
	free(result);
}
