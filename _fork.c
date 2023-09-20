#include "shell.h"

/**
 * _fork - creates a child process
 * @arr: A pointer to an argument vector
 * @env: A pointer to environment variables
 * @status: The integer value of the return status
 *
 */
void _fork(char **arr, char **env, int *status)
{
	pid_t pid;
	int st;

	pid = fork();
	if (pid == -1)
	{
		_free(arr);
		perror("Fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(arr[0], arr, env);
		_free(arr);
		exit(EXIT_FAILURE);
	}

	wait(&st);
	if (st != 0)
		*status = 2;
	else
		*status = 0;
	_free(arr);
}
