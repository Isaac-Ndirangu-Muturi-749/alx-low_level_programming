#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format specifier.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args; /* Declare va_list variable to hold variable arguments */
	unsigned int i = 0;
	char *separator = ""; /* Initialize separator to an empty string */
	char *str;

	va_start(args, format);/* Initialize va_list var with va_start macro*/
	while (format && format[i])/* Iterate through the format string */
	{
		switch (format[i]) /* Check the current character in format */
		{
			/* Print a character */
		case 'c':
			printf("%s%c", separator, va_arg(args, int));
			break;
			/* Print an integer */
		case 'i':
			printf("%s%d", separator, va_arg(args, int));
			break;
			/* Print a float */
		case 'f':
			printf("%s%f", separator, va_arg(args, double));
			break;
			/* Retrieve the next argument of type char* */
		case 's':
			str = va_arg(args, char *);
			/* If string is NULL, set it to (nil) */
			if (str == NULL)
				str = "(nil)";
			/* Print the string */
			break;
			printf("%s%s", separator, str);
		default:
			i++; /* Ignore any other character */
			continue;
		}
		separator = ", ";/* Update the separator to separate values */
		i++;
	}
	va_end(args); /* Clean up the va_list variable with va_end macro */
	printf("\n"); /* Print a new line at the end */
}
