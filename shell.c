#include "shell.h"

/**
 * main - Entry point
 * @ac: Number of arguments passed to the program
 * @av: A pointer to an array of arguments passed to the program
 *
 * Description: Simple Shell (CLI)
 *
 * Return: 0 on sucsess
 */
int main(int ac, char **av)
{
	char *buf = NULL, **arr, *delim = " \n", **env = environ;
	char **sep_arr;
	size_t n = 0;
	char *program;
	unsigned int t = 0, *m = &t, i;
	int status = 0;

	(void)ac;
	program = av[0];
	if (file_input(av, env, buf, program, m, &status, delim) == 0)
		return (0);

	while (1)
	{
		/* Check if the input stream is from terminal */
		_isatty();
		if (getline(&buf, &n, stdin) == -1)
			break;
		/* parse the command and handle it properly */
		if (xs_space(buf) == -1)
			continue;
		sep_arr = split_string(buf, ";\n");

		for (i = 0; sep_arr[i]; i++)
		{
			arr = split_string(sep_arr[i], delim);
			handle_command(arr, env, buf, program, m, sep_arr, &status);
		}
		_free(sep_arr);


	}

	free(buf);
	_exit(EXIT_SUCCESS);
}
