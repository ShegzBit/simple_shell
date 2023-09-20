#include "shell.h"

unsigned int get_words(char *s);
char **split_string(char *str, const char *delim);

/**
 * get_words - returns the number of words in a string
 * @s: The string to be tranversed
 *
 * Return: The number of words counted
 */
unsigned int get_words(char *s)
{
	unsigned int i, len = 0, spaced = 0;
	char space = ' ';

	for (i = 0; s[i]; i++)
	{
		if (s[i] == space)
		{
			if (spaced == 0)
				++len;
			spaced = 1;
			continue;
		}
		spaced = 0;
	}

	return (len + 1);
}

/**
 * split_string - splits a string and returns an array of
 *	each word of the string.
 * @str: The string to split.
 * @delim: The string delimiter
 *
 * Return: An array of split word.
 */
char **split_string(char *str, const char *delim)
{
	char *token, **arr;
	unsigned int n_words, i;

	if (str == NULL || delim == NULL)
		return (NULL);

	n_words = get_words(str);
	/* Allocate memory for an array of size nwords */
	arr = malloc(sizeof(char *) * (n_words + 1));
	if (arr == NULL)
		return (NULL);

	/* Get and save each token in the array */
	i = 0;
	token = strtok(str, delim);
	while (token)
	{
		arr[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	arr[i] = NULL;

	return (arr);
}
