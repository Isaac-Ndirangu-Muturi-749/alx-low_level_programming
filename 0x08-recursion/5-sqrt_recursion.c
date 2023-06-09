#include "main.h"

/**
 * sqrt_helper - Helper function to calculate the
 * square root using binary search
 * @n: input number
 * @start: starting point for the search
 * @end: ending point for the search
 * Return: natural square root of n, or
 * -1 if n does not have a natural square root
 */
int sqrt_helper(int n, int start, int end)
{
	int mid; int square;

	/* Return -1 if n does not have a natural square root*/
	if (start > end)
		return (-1);

	mid = start + (end - start) / 2;
	square = mid * mid;

	/* Base case: square of mid is equal to n, so mid is the square root*/
	if (square == n)
		return (mid);

	/* Recursively search in the upper half*/
	if (square < n)
		return (sqrt_helper(n, mid + 1, end));

	/* Recursively search in the lower half*/
	return (sqrt_helper(n, start, mid - 1));
}

/**
 * _sqrt_recursion - Calculate the natural square root of a number
 * @n: input number
 * Return: natural square root of n, or
 * -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	/* Return -1 to indicate an error if n is negative*/
	if (n < 0)
		return (-1);
	/* Base cases: square root of 0 is 0, square root of 1 is 1*/
	if (n == 0 || n == 1)
		return (n);

	/* Call a helper function to perform the square root calculation*/
	return (sqrt_helper(n, 0, n / 2));
}
