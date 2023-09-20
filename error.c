#include "shell.h"

/**
 * _error - displays error message and exit with appropriate satus
 * @program: The first argument received from the main function
 * @command: A pointer to an array of malloc'ed arguments received from stdin
 * @buf: The buffer used for stdin commands
 * @n: A pointer to the count of error encountered
 * @sep_arr: A pointer to an array of arguments for separated command
 */
void _error(char *program, char **command, char *buf,
		unsigned int *n, char **sep_arr)
{
	(*n)++;
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	put_u_int(*n);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, *command, _strlen(*command));
	write(STDERR_FILENO, ": not found\n", 12);

	if (!isatty(STDIN_FILENO))
	{
		free(buf);
		_free(sep_arr);
		_free(command);
		exit(127);
	}
}

/**
 * _error_cd - displays error message for cd
 * @program: The first argument received from the main function
 * @command: A pointer to an array of malloc'ed arguments received from stdin
 * @buf: The buffer used for stdin commands
 * @n: A pointer to the count of error encountered
 * @sep_arr: A pointer to an array of arguments for separated command
 */
void _error_cd(char *program, char **command, char *buf,
		unsigned int *n, char **sep_arr)
{
	(*n)++;
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	put_u_int(*n);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "cd", 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, command[1], _strlen(command[1]));
	_putchar_err('\n');

	if (!isatty(STDIN_FILENO))
	{
		free(buf);
		_free(sep_arr);
		_free(command);
		exit(0);
	}
}

/**
 * _error_exit - displays error message on illegal exit
 * @program: The first argument received from the main function
 * @command: A pointer to an array of malloc'ed arguments received from stdin
 * @buf: The buffer used for stdin commands
 * @n: A pointer to the count of error encountered
 */
void _error_exit(char *program, char **command, char *buf, unsigned int *n)
{
	(*n)++;
	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	put_u_int(*n);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "exit", 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, command[1], _strlen(command[1]));
	_putchar_err('\n');

	if (!isatty(STDIN_FILENO))
	{
		free(buf);
		_free(command);
		exit(2);
	}
}
