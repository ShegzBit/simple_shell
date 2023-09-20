#include "shell.h"

/**
 * _isatty - tests whether a file descriptor refers to a terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "($) ", 4);
		fflush(stdout);
	}
}
