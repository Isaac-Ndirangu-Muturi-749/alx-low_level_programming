#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to check
 *
 * Return: Returns the value of the last digit
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (n < 0)
	{
		n = -n;
	}

	_putchar(last_digit + '0');
	return (last_digit);
}
