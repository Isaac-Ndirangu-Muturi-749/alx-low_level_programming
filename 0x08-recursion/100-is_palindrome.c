#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: input string
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = strlen(s);
	int i, j;

	/* Base case: */
	/*an empty string or a string with a single character is a palindrome */
	if (length == 0 || length == 1)
		return (1);

	/* Compare characters from the beginning and the end of the string */
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		/* Characters at the corresponding positions don't match,*/
		/* not a palindrome */
		if (s[i] != s[j])
			return (0);
	}

	return (1); /* All characters match, the string is a palindrome */
}
