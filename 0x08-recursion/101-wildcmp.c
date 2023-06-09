#include <stdio.h>
#include "main.h"

/**
 * wildcmp - compares two strings considering the special character *
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Base cases: if both strings are empty, they are identical */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If the current characters match */
	/* or s2 has a wildcard '*', move to the next characters */
	if (*s1 == *s2 || *s2 == '*')
		return (wildcmp(s1 + 1, s2 + 1));

	/* If s2 has a wildcard '*', */
	/* try matching s1 with and without the current character in s2 */
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	/* If none of above conditions are met, the strings are not identical */
	return (0);
}
