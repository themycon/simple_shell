#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
 * main - Entry point of the simple shell program
 * @argc: The number of arguments passed to the program.
 * @argv: The array of argument strings, where argv[0] is the program name.
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{
	char *input_line = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;
	char **arguments;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		bytes_read = read_input(&input_line, &buffer_size);
		if (bytes_read == -1)
		{
			handle_eof();
			break;
		}

		if (bytes_read > 0 && input_line[bytes_read - 1] == '\n')
			input_line[bytes_read - 1] = '\0';

		arguments = parse_input(input_line);
		if (arguments[0] != NULL)
		{
			execute_command(arguments, argv[0]);
		}
		free(arguments);
	}

	free(input_line);
	return (0);
}
