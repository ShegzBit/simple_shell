#include "shell.h"

/**
 * _echo - mimics echo
 * @command: pointer to string to be printed
 */
void _echo(char **command)
{
	int len = _strlen(command[1]), i;

	if (command[1][0] == '"' && command[1][len - 1] == '"')
	{
		/* "cat" */
		for (i = 1; command[1][i] != '"'; i++)
		{
			if (command[1][i] == '\\')
				continue;
			_putchar(command[1][i]);
		}
	}
	else
	{
		for (i = 0; command[1][i]; i++)
		{
			if (command[1][i] == '\\')
				continue;
			_putchar(command[1][i]);
		}
	}
	_putchar('\n');
}
