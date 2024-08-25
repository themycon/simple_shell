#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * execute_command - Create a child process and execute the command.
 *
 * @arguments: Array of command and arguments to execute.
 */

void print_error(char *command)
{
	char *error_prefix = "./hsh: ";
	char *error_suffix = ": not found\n";
	int prefix_len = my_strlen(error_prefix);
	int command_len = my_strlen(command);
	int suffix_len = my_strlen(error_suffix);

	write(STDERR_FILENO, error_prefix, prefix_len);
	write(STDERR_FILENO, command, command_len);
	write(STDERR_FILENO, error_suffix, suffix_len);
}

char *get_command(char **arguments)
{
	char *command = NULL;

	if (access(arguments[0], F_OK) == 0)
	{
		command = arguments[0];
	}else
	{
		command = find_in_path(arguments[0]);
		if (command == NULL)
		{
		print_error(arguments[0]);
		}
	}
	return (command);
}

void execute_command(char **arguments)
{
	pid_t child_pid;
	int child_status;
	char *command;

	if (my_strcmp(arguments[0], "exit")==0)
	{
		free(arguments);
		exit(0);
	}

	command= get_command(arguments);
	if (command == NULL)
	{
		return;
	}


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(command, arguments, environ) == -1)
		{
		print_error(arguments[0]);
		exit(EXIT_FAILURE);
		}
	}
	else
	{
	wait(&child_status);
	}
	free(command);
}

/**
 * find_in_path - Search for a command in the PATH.
 * @command: Command to search for.
 *
 * Return: Full path to the command if found, otherwise NULL.
 */
char *find_in_path(char *command)
{
	char *path =my_get_env("PATH");
	char *path_copy = malloc(my_strlen(path) + 1);
	char *dir;
	char *full_path = malloc(PATH_MAX);
/**
 * size_t command_len = my_strlen(command);
 */

	if (!path || !path_copy || !full_path)
		return (NULL);

	my_strcpy(path_copy, path);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		my_strcpy(full_path, dir);
		my_strcat(full_path, "/");
		my_strcat(full_path, command);

		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		dir = strtok(NULL, ":");

	}

	free(path_copy);
	free(full_path);
	return (NULL);

}
