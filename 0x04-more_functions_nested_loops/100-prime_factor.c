#include "main.h"

/**
 * largest_prime_factor - Finds the largest prime factor of a given number
 * @n: The number
 *
 * Return: The largest prime factor
 */
long largest_prime_factor(long n)
{
	long i, largest_factor;

	largest_factor = -1;

	/*Divide n by 2 until it is no longer divisible by 2*/
	while (n % 2 == 0)
	{
		largest_factor = 2;
		n /= 2;
	}

	/*Check for prime factors starting from 3*/
	for (i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			largest_factor = i;
			n /= i;
		}
	}

	/*If n is a prime number greater than 2, it becomes the largest factor*/
	if (n > 2)
		largest_factor = n;

	return (largest_factor);
}
