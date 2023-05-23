#include <stdio.h>

/**
 * main - Prints all possible different combinations of four digits
 *
 * Return: Always 0
 */
int main(void)
{
	int num1, num2, num3, num4;

	for (num1 = 0; num1 <= 9; num1++)
	{
		for (num2 = num1 + 1; num2 <= 9; num2++)
		{
			for (num3 = num2 + 1; num3 <= 9; num3++)
			{
				for (num4 = num3 + 1; num4 <= 9; num4++)
				{
					putchar(num1 + '0');
					putchar(num2 + '0');
					putchar(num3 + '0');
					putchar(num4 + '0');

					if (num1 != 6 || num2 != 7 || num3 != 8 || num4 != 9)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
