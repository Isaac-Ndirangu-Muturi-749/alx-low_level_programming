#include "main.h"

/**
 * is_prime_number - checks if a number is prime
 * @n: input number
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	int i;

	/* Base cases */
	if (n <= 1)
		return (0);  /* Numbers less than or equal to 1 are not prime*/

	/* Check for divisibility */
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);  /* n is divisible by i, so it is not prime*/
	}

	return (1);  /* n is not divisible by any numbers, so it is prime*/
}
