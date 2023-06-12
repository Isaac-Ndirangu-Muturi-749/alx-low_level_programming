#include <stdio.h>

/**
 * main -  a program that prints its name, followed by a new line
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/* Accessing the program name from argv[0]*/
	printf("%s\n", argv[0]);

	return (0);
}
