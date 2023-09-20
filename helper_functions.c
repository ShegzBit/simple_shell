#include "shell.h"

int _atoi(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);

/**
 * _atoi - converts string to number
 * @s: strings to be converted
 *
 * Return: The value of the converted string.
 */
int _atoi(char *s)
{
	int sign;
	unsigned int num;

	sign = 1;
	num = 0;
	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if ((*s >= '0') && (*s <= '9'))
		{
			num = (num * 10) + (*s - '0');
		}
		else if (num > 0)
		{
			break;
		}
		s++;
	}
	return (num * sign);
}

/**
 * _strdup - duplicate a string
 * @str: string to be duplicated
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 *	NULL if str = NULL
 *	NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *s;
	int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';

	return (s);
}

/**
 * _strcmp - compares two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 == s2, (-) if s1 is less and (+) if s2 is greater
 */
int _strcmp(char *s1, char *s2)
{
	int l1 = strlen(s1), l2 = strlen(s2), count = 0;

	if (l1 != l2)
		return (-1);
	for (count = 0; s1[count] && s2[count]; count++)
		if (s1[count] != s2[count])
			return (-1);
	return (0);
}

/**
 * _strlen - returns the length of a string
 * @s: string to return its length
 *
 * Return: len, as the length of the string.
 */
int _strlen(const char *s)
{
	int lens, i;

	lens = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		lens++;
	}
	return (lens);
}

/**
 * _strcpy -  copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy to
 * @src: string source
 *
 * Return: copied string in dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';


	return (dest);
}
