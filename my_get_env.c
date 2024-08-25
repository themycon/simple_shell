#include "shell.h"

/**
 * my_get_env - find the value of an environment var
 * @var_name: Name of the environment variable to search for
 *
 * Return: Value of the environment variable, or NULL if not found
 */
char *my_get_env(const char *var_name)
{
	int i = 0;
	size_t len = my_strlen(var_name);

	while (environ[i])
	{
		if (my_strncmp(environ[i], var_name, len) == 0 && (environ[i])[len] == '=')
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}

	return (NULL);
}
