#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to be printed
 */
void print_number(int n)
{
	/* Check if the number is negative */
	if (n < 0)
	{
		_putchar('-'); /* Print the minus sign */
		n = -n; /* Update n to its absolute value */
	}

	/* Recursive call to print each digit */
	if (n / 10)
	{
		/* Call the function with the integer division of n by 10 */
		print_number(n / 10);

	}

	/* Print the last digit */
	/* Print the digit by adding '0' to the remainder of n divided by 10 */
	_putchar('0' + (n % 10));
}
