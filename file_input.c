#include "shell.h"

/**
 * file_input - handles file as input case
 * @av: argument vector passed to main containing file
 * passed as argument
 * @env: environment variables to update when needed
 * @buf: unparsed command <not an array of command yet>
 * string passed in by user
 * @program: name of program being run
 * usually first word in buf and arr
 * @m: A pointer to shell program error counter.
 * @delim: the delim for spliting the string
 * @status: The integer value of the return status
 * Return: 'x' in case of excess space passed as filename
 * or no filename passed | 0 otherwise
 */
int file_input(char **av, char **env, char *buf,
		char *program, u_int *m, int *status, char *delim)
{
	char *file = av[1], *buffer = NULL;
	char **arr, **sep_arr;
	size_t size = 0;
	int nread = 0, i;
	FILE *file_holder = NULL;

	if (file == NULL || xs_space(file) == -1)
		return ('x');
	if (access(file, F_OK) == -1)
	{
		write(STDERR_FILENO, program, _strlen(program));
		write(STDERR_FILENO, ": ", 2);
		put_u_int(*m);
		write(STDERR_FILENO, ": Can't open ", 13);
		write(STDERR_FILENO, file, _strlen(file));
		_putchar_err('\n');
		exit(127);
	}
	file_holder = fopen(file, "r");
	while ((nread = getline(&buffer, &size, file_holder)) > 0)
	{
		if (xs_space(buffer) == -1 || _strcmp(buffer, "#!/bin/bash\n") == 0)
			continue;
		sep_arr = split_string(buffer, ";\n");
		for (i = 0; sep_arr[i]; i++)
		{
			arr = split_string(sep_arr[i], delim);
			handle_command(arr, env, buf, program, m, sep_arr, status);
		}
		_free(sep_arr);
	}
	free(buffer);
	fclose(file_holder);
	return (0);
}
