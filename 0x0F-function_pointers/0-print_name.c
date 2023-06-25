#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - print name using pointer to function
 * @name: string to print
 * @f: pointer to function that prints the name
 *
 * Description: This function takes a string `name` and a function pointer `f`
 *              as arguments. It checks for null pointers and then calls the
 *              function pointed to by `f` with the `name` as the argument.
 *
 * Return: void
 **/
void print_name(char *name, void (*f)(char *))
{
	/* Check if either name or f is a null pointer*/
	if (name == NULL || f == NULL)
		return;

	/* Call the function pointed to by f, passing the name as the argument*/
	f(name);
}
