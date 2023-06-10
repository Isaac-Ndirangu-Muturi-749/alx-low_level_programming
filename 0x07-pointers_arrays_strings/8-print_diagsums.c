#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: The pointer to the square matrix.
 * @size: The size of the matrix.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0; /* Sum of the main diagonal */
	int sum2 = 0; /* Sum of the secondary diagonal */

	/* Calculate the sum of the main diagonal and the secondary diagonal */
	for (i = 0; i < size; i++)
	{
		/* Elements on the main diagonal have same row & column index */
		sum1 += a[i * size + i];
		/* Elements on the secondary diagonal have the row index*/
		/*  increasing and the column index decreasing */
		sum2 += a[i * size + (size - 1 - i)];
	}

	/* Print the sum of the diagonals */
	printf("Sum of main diagonal: %d\n", sum1);
	printf("Sum of secondary diagonal: %d\n", sum2);
}
