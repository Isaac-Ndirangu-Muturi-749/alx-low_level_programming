#include "main.h"

/**
 * print_number - a function that prints an integer.
 * @n: integer to be printed
 * Return: 0
 */
void print_number(int n)
{
	unsigned int n1;

	n1 = n;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}

	/* Recursive call to print each digit */
	if (n1 / 10 != 0)
	{
		print_number(n1 / 10);
	}

	/* Print the current digit */
	_putchar((n1 % 10) + '0');
}
