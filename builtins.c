#include "shell.h"

int check_builtin(char **command);
void _printenv(char **env);
void _exit_cp(char **command, char *buf, char **sep_arr,
		char *program, unsigned int *n, int *status);
void handle_builtin(char **command, char *buf, char **env,
		char **sep_arr, int *status, char *program, unsigned int *n);

/**
 * check_builtin - checks if a command is part of
 * implemented builtins
 *
 * @command: pointer to command to check for
 * Return: 0 if builtin | -1 otherwise
 */
int check_builtin(char **command)
{
	char *builtins[] = {"exit", "env", "printenv", "setenv", "cd",
		"unsetenv", "echo", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
		if (_strcmp(command[0], builtins[i]) == 0)
			return (0);
	return (-1);
}

/**
 * _printenv - prints the local processes environment
 * variable
 *
 * @env: environment variable
 */
void _printenv(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		_putchar('\n');
	}
}

/**
 * _exit_cp - terminates the calling process
 * @command: A pointer to an array of character pointers  passed to the program
 * @buf: A temporary buffer used by the program
 * @sep_arr: An array of ; separated commands.
 * @program: The program name
 * @n: The error counter.
 * @status: The integer value of the return status
 */
void _exit_cp(char **command, char *buf, char **sep_arr,
		char *program, unsigned int *n, int *status)
{
	int st;
	char *exit_status;

	if (command[1])
	{
		exit_status = command[1];
		if (_isdigit(exit_status) == -1)
		{
			_free(sep_arr);
			_error_exit(program, command, buf, n);
		}
		st = _atoi(exit_status);
	}
	else
		st = *status;
	free(buf);
	_free(command);
	_free(sep_arr);
	_exit(st);
}

/**
 * handle_builtin - handles builtins if implemented
 * @command: pointer to command to compare
 * @buf: passed buf to free
 * @env: to printenv
 * @sep_arr: An array of ; separated commands.
 * @status: The integer value of the return status
 * @program: The program name
 * @n: The error counter.
 */
void handle_builtin(char **command, char *buf, char **env,
		char **sep_arr, int *status, char *program, unsigned int *n)
{
	if (_strcmp(command[0], "exit") == 0)
		_exit_cp(command, buf, sep_arr, program, n, status); /* cd*/
	if (_strcmp(command[0], "cd") == 0)
		cd(env, command, program, buf, n, sep_arr); /*Env*/
	if (_strcmp(command[0], "env") == 0 ||
			_strcmp(command[0], "printenv") == 0)
		_printenv(env); /*Setenv*/
	if ((_strcmp(command[0], "setenv") == 0) && command[1] && command[2])
	{
		if ((_setenv(env, command[1], command[2]) == -1))
			write(STDERR_FILENO, "Error: setenv failed\n", 21);
	} /*Unsetenv*/
	if ((_strcmp(command[0], "unsetenv") == 0) && command[1])
	{
		if ((_unsetenv(env, command[1]) == -1))
			write(STDERR_FILENO, "Error: unsetenv failed\n", 23);
	} /*Echo*/
	if ((_strcmp(command[0], "echo") == 0) && command[1])
	{
		if ((command[1][0] == '$') && (command[1][1] == '?'))
			_echo_status(status);
		else if ((command[1][0] == '$') && (command[1][1] == '$'))
			_getpid();
		else if ((command[1][0] == '$') && ((command[1][1] != '?') ||
					(command[1][1] != '$')))
		{
			_puts(_getenv(&(command[1][1])));
			_putchar('\n');
		}
		else
			_echo(command);
	}
}
