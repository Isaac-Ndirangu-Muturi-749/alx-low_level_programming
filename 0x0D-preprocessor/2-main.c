#include <stdio.h>

/**
 * main - a program that prints the name of the file it was compiled from,
 * followed by a new line
 *
 * Return: 0 if successful
 */

int main()
{
	printf("Compiled from file: %s\n", __FILE__);
	return (0);
}
