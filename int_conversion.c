#include "shell.h"

int _putchar_err(char c);
int _puts(char *s);
void reverse(char *s);
int put_int(int num);
int put_u_int(unsigned int num);

/**
 * _putchar_err - prints a char
 * @c: char to print
 * Return: char length = 1;
*/
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}

/**
 * _puts - prints a string
 * @s: str to print
 * Return: str length
*/
int _puts(char *s)
{
	char *str = (s == NULL) ? "(null)" : s;
	int i = 0, retval = 0;

	while (str[i])
	{
		retval += _putchar_err(str[i++]);
	}

	return (retval);
}


/**
 * put_int - prints integer
 * @num: number to be printed
 * Return: length of num
*/
int put_int(int num)
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
	count = _puts(str);
	free(str);
	return (count);
}

/**
 * put_u_int - prints unsigned integer
 * @num: The number to be printed
 *
 * Return: The length of the printed num
*/
int put_u_int(unsigned int num)
{
	int i = 0, count;
	char s[INT_BUFFER_SIZE];

	if (num == 0)
	{
		return (_puts("0"));
	}
	else
	{
		while (num > 0)
		{
			s[i++] = (num % 10) + '0';
			num /= 10;
		}
		s[i] = '\0';
	}

	reverse(s);
	count = _puts(s);

	return (count);
}

/**
 * reverse - reverses a string
 * @s: string to reverse*
 */
void reverse(char *s)
{
	int len, i, tmp;

	len = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	for (i = len - 1; i >= len / 2 ; i--)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}
