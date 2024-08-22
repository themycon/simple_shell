#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include "shell.h"

/* Function prototypes */
void handle_eof(void);
ssize_t read_input(char **input_line, size_t *buffer_size);
void execute_command(char *command);

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	char *input_line = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		printf("#cisfun$ ");
		bytes_read = read_input(&input_line, &buffer_size);
		if (bytes_read == -1)
	{
		handle_eof();
		break;
	}

		if (input_line[bytes_read - 1] == '\n')
		input_line[bytes_read - 1] = '\0';

		execute_command(input_line);
	}

	free(input_line);
	return (0);
}

/**
 * handle_eof - Handle end-of-file (EOF) conditions.
 */
void handle_eof(void)
{
	if (feof(stdin))
	printf("\n");
	else
	perror("getline error");
}

/**
 * read_input - Read a line of input from stdin.
 *
 * @input_line: Pointer to buffer where input will be stored.
 * @buffer_size: Size of the buffer.
 *
 * Return: Number of bytes read, or -1 if error.
 */
ssize_t read_input(char **input_line, size_t *buffer_size)
{
	return (getline(input_line, buffer_size, stdin));
}

/**
 * execute_command - Create a child process and execute the command.
 *
 * @command: Command to be executed.
 */
void execute_command(char *command)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();
	if (child_pid == -1)
	{
	perror("fork error");
	return;
	}

	if (child_pid == 0)
	{
	char *arguments[] = {command, NULL};

	if (execve(command, arguments, environ) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		wait(&child_status);
	}
}
