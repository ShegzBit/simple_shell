#include "shell.h"

/**
 * cpy_env - copies new memory of previous array of environs to a new array
 * @dest_env: New environment array
 * @src_env: previous environment array
 * @count: The number of elements in the previous environment array
 */
void cpy_env(char **dest_env, char **src_env, size_t count)
{
	size_t i;

	for (i = 0; i < count; i++)
	{
		dest_env[i] = src_env[i];
	}
}

/**
 * count_env - counts the number of present environmets
 * @env: Environment to be counted
 *
 * Return: the numbers of elements present in the environment
 */
size_t count_env(char **env)
{
	size_t i;

	for (i = 0; env[i]; i++)
		;

	return (i);
}

/**
 * make_env - concatenates a key to a value to be added to the environment
 * @name: The new environment key
 * @value: the new environment value
 *
 * Return: A pointer to the new environment variable
 */
char *make_env(const char *name, const char *value)
{
	char *new_env;
	char *name_c, *value_c;
	size_t i, j, size, name_len = strlen(name), value_len = strlen(value);

	size = name_len + value_len + 2;
	new_env = malloc(sizeof(char) * size);
	if (new_env == NULL)
		return (NULL);
	name_c = strdup(name);
	value_c = strdup(value);

	/* Copy name strings */
	for (i = 0; name_c[i]; i++)
		new_env[i] = name_c[i];

	new_env[i++] = '=';
	/* Copy value strings */
	for (j = 0; value_c[j]; j++)
		new_env[i + j] = value_c[j];

	new_env[i + j] = '\0';

	free(name_c);
	free(value_c);

	return (new_env);
}

/**
 * overwrite_env - overwrites an existing environment
 * @env: The environment variable
 * @name: Environment variable key
 * @new_env: New envronment variable to overwrite with
 * @key_len: The length of the environment key
 */
void overwrite_env(char **env, const char *name, char *new_env, size_t key_len)
{
	for (; *env; env++)
	{
		if ((_strncmp(*env, name, key_len) == 0) && ((*env)[key_len] == '='))
			_strcpy(*env, new_env);
	}
}

/**
 * _setenv - changes or adds an environment variable
 * @env: The environment variable
 * @name: The variable key
 * @value: The variable value
 *
 * Return: 0 on sucsess, or -1 on failure
 */
int _setenv(char **env, const char *name, const char *value)
{
	char *new_env, **new_environ;
	size_t key_len, count;
	char buf[256];
	char buff[10];

	if (name == NULL || value == NULL)
		return (-1);
	key_len = strlen(name);
	new_env = make_env(name, value);
	if (_getenv(name))
	{
		/* Add new_env to environ */
		overwrite_env(env, name, new_env, key_len);
		free(new_env);
		return (0);
	}
	if (!_getenv(name))
	{
		count = count_env(env);
		/* Allocate memory of size count + 2 for the new_environ */
		new_environ = malloc(sizeof(char *) * (count + 2));
		if (new_environ == NULL)
		{
			free(new_env);
			return (-1);
		}
		cpy_env(new_environ, env, count);
		new_environ[count] = buf;
		_strcpy(new_environ[count], new_env);
		new_environ[count + 1] = buff;
		new_environ[count + 1] = NULL;
		/* Update environ to new_environ */
		env = new_environ;

		free(new_env);
		free(new_environ);
		return (0);
	}
	free(new_env);
	return (-1);
}
