#include "shell.h"

/**
 * cd - changes directory
 * @env: environ to edit
 * @command: A pointer to an array of commands passed to the program
 * @program: The name of the program
 * @buf: The buffer used to get command line arguments
 * @n: The errror counter
 * @sep_arr: A pointer to an array of arguments for separated command
 */
void cd(char **env, char **command, char *program, char *buf,
		unsigned int *n, char **sep_arr)
{
	char buff[1024];
	char buf_2[1024];
	char *cwd = getcwd(buff, BUFFER);
	char *home = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");
	char *current_dir = NULL;

	if (command[1])
	{
		if ((_strcmp(command[1], "-") == 0) && old_dir)
		{
			if (chdir(old_dir) == -1)
				_error_cd(program, command, buf, n, sep_arr);
			write(STDOUT_FILENO, old_dir, _strlen(old_dir));
			_putchar('\n');
		}
		if ((_strcmp(command[1], "-") == 0) && !old_dir)
		{
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			_putchar('\n');
		}

		if ((_strcmp(command[1], "-") != 0))
			if (chdir(command[1]) == -1)
			{
				write(STDOUT_FILENO, cwd, _strlen(cwd));
				_putchar('\n');
				_error_cd(program, command, buf, n, sep_arr);
			}
	}
	else if (home)
		if (chdir(home) == -1)
			_error_cd(program, command, buf, n, sep_arr);
	current_dir = getcwd(buf_2, BUFFER);
	_setenv(env, "PWD", current_dir);
	_setenv(env, "OLDPWD", cwd);
}
