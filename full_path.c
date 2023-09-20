#include "shell.h"

/**
 * make_full_path - concats directory  '/' and cmd
 * @dir: directory
 * @command: cmd
 *
 * Return: full command path
 */
char *make_full_path(char *dir, char *command)
{
	size_t size, i, j;
	char *full_path;

	size = _strlen(dir) + _strlen(command) + 2;
	full_path = malloc(sizeof(char) * size);
	if (!full_path)
		return (NULL);

	/* Concatenate the strings */
	for (i = 0; dir[i]; i++)
		full_path[i] = dir[i];

	full_path[i++] = '/';

	for (j = 0; command[j]; j++)
		full_path[i + j] = command[j];

	full_path[i + j] = '\0';

	return (full_path);
}

/**
 * search_path - searches if command exists in path
 * @command: command to search
 * @program: The argument one that is used to call the main function
 * @buf: The buffer used to accept input from stdin
 * @n: A pointer to the number of error encountered when a command is not found
 * @sep_arr: A pointer to an array of arguments for separated command
 */
void search_path(char **command, char *program, char *buf,
		unsigned int *n, char **sep_arr)
{
	char *value, *dir, *full_path = NULL, *command_cpy;

	value = _strdup(_getenv("PATH"));

	dir = strtok(value, ":");
	while (dir)
	{
		full_path = make_full_path(dir, *command);
		if (access(full_path, F_OK) == 0)
		{
			command_cpy = *command;
			*command = full_path;
			free(value);
			free(command_cpy);
			return;
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	if (access(*command, F_OK) == -1)
		_error(program, command, buf, n, sep_arr);
	free(value);
}
