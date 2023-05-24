#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: n times table
 */
void print_times_table(int n)
{
	int row, col, prod;

	if (n >= 0 && n <= 15)
	{
		for (row = 0; row <= n; row++)
		{
			for (col = 0; col <= n; col++)
			{
				prod = row * col;
				if (col == 0)
				{
					_putchar(prod + '0');
				} else if (prod < 10 && col != 0)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar(prod + '0');
				} else if (col >= 10 && prod < 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar((prod / 10) + '0');
					_putchar((prod % 10) + '0');
				} else if (prod >= 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar((prod / 100) + '0');
					_putchar(((prod / 10) % 10) + '0');
					_putchar((prod % 10) + '0');
				}
			}
			_putchar('\n');
		}
	}
}
