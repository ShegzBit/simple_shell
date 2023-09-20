#include "shell.h"

/**
 * rm_env - copies new memory of previous array of environs to a new array
 * @dest_env: New environment array
 * @src_env: previous environment array
 * @count: The number of elements in the previous environment array
 * @position: The position of the variable to unset
 */
void rm_env(char **dest_env, char **src_env, size_t count, size_t position)
{
	size_t i;

	for (i = 0; i < count; i++)
	{
		if (i == position)
			continue;
		dest_env[i] = src_env[i];
	}
}

/**
 * getenv_position - gets the position of the variable to unset
 * @env: The environment variable
 * @name: The key of the variable to remove
 *
 * Return: The position of the variable on success, or -1 on failure
 */
int getenv_position(char **env, const char *name)
{
	size_t key_len = _strlen(name);
	int i;

	for (i = 0; env[i]; i++)
	{
		if ((_strncmp(env[i], name, key_len) == 0) && (env[i][key_len] == '='))
			return (i);
	}
	return (-1);
}

/**
 * _unsetenv - remove an environment variable
 * @env: The environment variable
 * @name: The key of the variable to be removed
 *
 * Return: 0 on success, -1 otherwise
 */
int _unsetenv(char **env, const char *name)
{
	char **new_env;
	int position;
	size_t count;

	if (_getenv(name))
	{
		position = getenv_position(env, name);
		if (position == -1)
			return (-1);

		count = count_env(env);

		/* Allocate memory of size count for the new_env */
		new_env = malloc(sizeof(char *) * count);
		if (new_env == NULL)
			return (-1);
		rm_env(new_env, env, count, position);
		new_env[count - 1] = NULL;

		/* Update environ to new_environ */
		env = new_env;

		free(new_env);
		return (0);
	}
	else
		return (0);
}
