#include "main.h"

/**
 * rot13 - encode a string using ROT13
 * @str: input string to be encoded
 * Return: encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	/* Iterate through each character in the input string */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* Check if the character is an alphabet */
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			/* Find the corresponding encoded character */
			for (j = 0; j < 52; j++)
			{
				if (str[i] == input[j])
				{
					str[i] = output[j];
					break;
				}
			}
		}
	}
	return (str);
}
