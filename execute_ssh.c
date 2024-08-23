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

size_t my_strlen(const char *s)
{
	size_t len = 0;
	while (s[len] != '\0')
	len++;
	return (len);
}

void execute_command(char **arguments)
{
	pid_t child_pid;
	int child_status;
	char *error_prefix = "./hsh: ";
	char *error_suffix = ": not found\n";
	int prefix_len = my_strlen(error_prefix);
	int command_len = my_strlen(arguments[0]);
	int suffix_len = my_strlen(error_suffix);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
		write(STDERR_FILENO, error_prefix, prefix_len);
		write(STDERR_FILENO, arguments[0], command_len);
		write(STDERR_FILENO, error_suffix, suffix_len);
		exit(EXIT_FAILURE);
		}
	}
	else
	{
	wait(&child_status);
	}
}
