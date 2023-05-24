#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: No return
 */
void times_table(void)
{
	int i, j, multiple;

	for (i = 0; i <= 9; i++)
	{
		_putchar('0');
		for (j = 1; j <= 9; j++)
		{
			_putchar(',');
			_putchar(' ');
			multiple = i * j;
			if (multiple <= 9)
			{
				_putchar(multiple + '0');
			}
			else
			{
				_putchar((multiple / 10) + '0');
				_putchar((multiple % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
