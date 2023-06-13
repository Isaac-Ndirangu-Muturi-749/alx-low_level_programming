#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count_words - counts the number of words in a string
 * @str: input string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;
	int is_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (is_word == 0)
			{
				is_word = 1;
				count++;
			}
		}
		else
		{
			is_word = 0;
		}
	}

	return (count);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to an array of strings (words),
 * or NULL if str is NULL, str is empty, or memory allocation fails
 */
char **strtow(char *str)
{
	int words, len, i, j, k;
	char **word_array;

	if (str == NULL || *str == '\0')
		return (NULL);
	words = count_words(str);
	word_array = (char **)malloc((words + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		len = 0;
		while (str[i + len] != ' ' && str[i + len] != '\0')
			len++;
		if (len > 0)
		{
			word_array[j] = (char *)malloc((len + 1) * sizeof(char));
			if (word_array[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(word_array[k]);
				free(word_array);
				return (NULL);
			}

			strncpy(word_array[j], str + i, len);
			word_array[j][len] = '\0';
			i += len;
			j++;
		}
		else
			i++;
	}
	word_array[j] = NULL;
	return (word_array);
}
