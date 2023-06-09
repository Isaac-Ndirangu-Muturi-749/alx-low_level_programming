#include "main.h"

/**
 * _sqrt_recursion - Calculate the natural square root of a number
 * @n: input number
 * Return: natural square root of n, or
 * -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	int i;

	/*Return -1 to indicate an error if n is negative*/
	if (n < 0)
		return (-1);

	/*Base cases: square root of 0 is 0, square root of 1 is 1*/
	if (n == 0 || n == 1)
		return (n);

	/* If i*i equals n, i is the square root of n*/
	for (i = 1; i <= n / 2; i++)
	{
		if (i * i == n)
			return (i);
		/* If i*i exceeds n, there is no natural square root*/
		else if (i * i > n)
			break;
	}

	/*Call a helper function to perform the remaining calculation*/
	return (sqrt_helper(n, i - 1, i));
}

/**
 * sqrt_helper - Helper function to perform the
 * remaining square root calculation
 * @n: input number
 * @start: starting point for the search
 * @end: ending point for the search
 * Return: natural square root of n, or
 * -1 if n does not have a natural square root
 */
int sqrt_helper(int n, int start, int end)
{
	while (start <= end)
	{
		/*Use a long long to avoid integer overflow*/
		int mid = start + (end - start) / 2;
		long long square = (long long)mid * mid;

		/*Base case square of mid is equal to n, so mid is square root*/
		if (square == n)
			return (mid);

		/* Adjust the start point if square is less than n*/
		if (square < n)
			start = mid + 1;
		/* Adjust the end point if square is greater than n*/
		else
			end = mid - 1;
	}

	/* Return -1 if n does not have a natural square root*/
	return (-1);
}
