#include "shell.h"

/* Custom strlen implementation */
size_t _strlen(const char *s)
{
	size_t len = 0;
	while (s[len] != '\0')
	len++;
	return len;
}

/* Custom strcpy implementation */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;
	while (*src)
	*ptr++ = *src++;
	*ptr = '\0';
	return dest;
}

/* Custom strcat implementation */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + _strlen(dest);
	while (*src)
	*ptr++ = *src++;
	*ptr = '\0';
return dest;
}

/* Custom function to get environment variable */
char *get_env_var(const char *name)
{
	int i = 0;
	size_t name_len = _strlen(name);
	
	while (environ[i])
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		return (&environ[i][name_len + 1]);
		i++;
	}
	return (NULL);
}

/* find_command_path function */
char *find_command_path(char *command)
{
	char *path = get_env_var("PATH");
	char *dir = NULL;
	char *full_path = NULL;
	char *path_copy = NULL;
	size_t command_len, dir_len;
	int command_found = 0;

	if (!path)
	return (NULL);
	command_len = _strlen(command);
	path_copy = malloc(_strlen(path) + 1);
	(!path_copy)
	return (NULL);
	
	_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	
	{
	dir_len = _strlen(dir);
	full_path = malloc(dir_len + command_len + 2); /* +2 for '/' and '\0' */
	if (!full_path)
	free(path_copy);
	return (NULL);
	

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	if (access(full_path, X_OK) == 0) /* Check if the command is executable */
	{

	command_found = 1;
		break;
	}

	
	free(full_path);
	full_path = NULL;
	dir = strtok(NULL, ":");
	}

	free(path_copy);
	if (command_found)
	return (full_path);
	else
	return (NULL);
}
