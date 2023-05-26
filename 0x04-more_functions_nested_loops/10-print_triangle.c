#include "main.h"

/**
 * print_triangle - Prints a triangle of a specified size.
 * @size: The size of the triangle.
 *
 */
void print_triangle(int size)
{
	int row, col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (col = 0; col <= i; col++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
