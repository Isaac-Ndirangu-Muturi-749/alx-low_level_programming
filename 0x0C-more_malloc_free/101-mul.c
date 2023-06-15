#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - checks if a string represents a positive number
 * @str: string to check
 *
 * Description: This function checks if a string contains only digits,
 *              indicating a positive number.
 *
 * Return: 1 if the string represents a positive number, 0 otherwise
 */
int is_positive_number(char *str)
{
	int i = 0;

	/* Iterate through the characters of the string */
	while (str[i] != '\0')
	{
		/* Check if the character is a digit */
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}



/**
 * multiply_numbers - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 *
 * Description: This function multiplies two positive numbers
 *              and prints the result.
 *
 * Return: void
 */
void multiply_numbers(char *num1, char *num2)
{
	int result;

	/* Check if num1 and num2 are positive numbers */
	if (!is_positive_number(num1) || !is_positive_number(num2))
	{
		/* Terminate the process with status value 98 */
		exit(98);
	}

	/* Perform the multiplication */
	result = atoi(num1) * atoi(num2);

	/* Print the result */
	printf("%d\n", result);
}
