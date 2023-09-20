#include "shell.h"

/**
 * handle_command - handles command appropraitely
 * either by calling builtin in or exec
 * @arr: arr of commands
 * @env: environment variables to update when needed
 * @buf: unparsed command <not an array of command yet>
 * string passed in by user
 * @program: name of program being run
 * usually first word in buf and arr
 * @m: A pointer to shell program error counter.
 * @sep_arr: An array of ';' separated commands.
 * @status: The integer value of the return status
 */
void handle_command(char **arr, char **env, char *buf, char *program,
		u_int *m, char **sep_arr, int *status)
{
	if (check_builtin(arr) == 0)
	{
		handle_builtin(arr, buf, env, sep_arr, status, program, m);
		_free(arr);
	}
	/* Process the command */
	else
	{
		search_path(arr, program, buf, m, sep_arr);

		/* Execute the input command*/
		_fork(arr, env, status);
	}
}
