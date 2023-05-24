#include"main.h"

/**
 * print_alphabet_x10-prints 10 times the alphabet, in lowercase, new line
 *
 * Return: No return
 */
void print_alphabet_x10(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}

		_putchar('\n');
	}
}
