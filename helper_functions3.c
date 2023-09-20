#include "shell.h"

int _putchar(char c);
int _isdigit(char *str);
int _puts_norm(char *s);
int put_int_norm(int num);

/**
 * _putchar - prints a char
 * @c: char to print
 * Return: char length = 1;
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @str: character pointer to check
 *
 * Return: 1 if c is a digit, 0 if otherwise
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

/**
 * _puts_norm - prints a string
 * @s: str to print
 * Return: str length
*/
int _puts_norm(char *s)
{
	char *str = (s == NULL) ? "(null)" : s;
	int i = 0, retval = 0;

	while (str[i])
	{
		retval += _putchar(str[i++]);
	}

	return (retval);
}

/**
 * put_int_norm - prints integer
 * @num: number to be printed
 * Return: length of num
*/
int put_int_norm(int num)
{
	/*declare str (size = 11) and othe variables*/
	char *str;
	int i = 0, store, count;

	if (num == 0)
		return (_puts("0"));
	str = malloc(12 * sizeof(char));
	if (str == NULL)
		return (-1);

	/*get absolute if num is negative*/
	store = num;
	if (num == INT_MIN)
	{
		str[i++] = '8';
		num /= 10;
	}
	if (num < 0)
	{
		num = -num;
	}
	/*store each digit in str by using % 10*/
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}

	/*if number is negative append a '-'*/
	if (store < 0)
	{
		str[i++] = '-';
	}
	/*reverse string and null terminate;*/
	str[i++] = '\0';
	reverse(str);
	count = _puts_norm(str);
	free(str);
	return (count);
}
