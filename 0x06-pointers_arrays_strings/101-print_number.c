#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	unsigned int n1;  /*Variable to store the absolute value of n*/

	n1 = (n < 0) ? -n : n;  /* Assign absolute value of n to n1*/

	if (n < 0)
		_putchar('-');  /*Print '-' sign for negative numbers*/

	/*Check if there are more digits to print*/
	/*Recursively call the function to print remaining digits*/
	if (n1 / 10 != 0)
		print_number(n1 / 10);

	_putchar((n1 % 10) + '0');  /*Print the rightmost digit using _putchar*/
}
