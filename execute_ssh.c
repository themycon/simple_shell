#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * print_error - prints error message std err if cmd is not found.
 * @prog_name: The name of the program (from argv[0]).
 * @command: command that led to the error.
 */

void print_error(char *prog_name, char *command)
{
	char *error_prefix = ": 1: ";
	char *error_suffix = ": not found\n";
	int prog_len = my_strlen(prog_name);
	int prefix_len = my_strlen(error_prefix);
	int command_len = my_strlen(command);
	int suffix_len = my_strlen(error_suffix);

	write(STDERR_FILENO, prog_name, prog_len);
	write(STDERR_FILENO, error_prefix, prefix_len);
	write(STDERR_FILENO, command, command_len);
	write(STDERR_FILENO, error_suffix, suffix_len);
}

/**
 * get_command - Retrieve the full command path or search in PATH.
 * @arguments: Array of command and arguments to execute.
 * @prog_name: The name of the program
 *
 * Return: Full path to the command if found, otherwise NULL.
 */

char *get_command(char **arguments, char *prog_name)
{
	char *command = NULL;

	if (access(arguments[0], F_OK) == 0)
	{
		command = arguments[0];
	} else
	{
		command = find_in_path(arguments[0]);
		if (command == NULL)
		{
		print_error(prog_name, arguments[0]);
		}
	}
	return (command);
}

/**
 * execute_command - Create a child process and execute the command.
 * @arguments: Array of command and arguments to execute.
 * @prog_name: The name of the program
 */

void execute_command(char **arguments, char *prog_name)
{
	pid_t child_pid;
	int child_status;
	char *command;

	if (my_strcmp(arguments[0], "exit") == 0)
	{
		free(arguments);
		exit(0);
	}

	command = get_command(arguments, prog_name);
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
		print_error(prog_name, arguments[0]);
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
	char *path = my_get_env("PATH");
	char *path_copy = malloc(my_strlen(path) + 1);
	char *dir;
	char *full_path;

	if (!path || !path_copy)
	{
	return (NULL);
	}

	my_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
	full_path = malloc(my_strlen(dir) + my_strlen(command) + 2);
	if (!full_path)
	{
		free(path_copy);
		return (NULL);
	}

	my_strcpy(full_path, dir);
	my_strcat(full_path, "/");
	my_strcat(full_path, command);

	if (access(full_path, F_OK) == 0)
	{
		free(path_copy);
		return (full_path);
	}

	free(full_path);
	dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
