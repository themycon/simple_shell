#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * handle_eof - Handle end-of-file (EOF) conditions.
 */
void handle_eof(void)
{
	if (feof(stdin))
	write(STDOUT_FILENO, "\n ", 9);
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
 * parse_input - Parse input line into an array of arguments.
 *
 * @input_line: Input line to parse.
 *
 * Return: An array of arguments.
 */
char **parse_input(char *input_line)
{
	char **arguments = malloc(64 * sizeof(char *));
	char *token;
	int index = 0;

	if (arguments == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_line, " \t");
	while (token != NULL)
	{
		arguments[index] = token;
		index++;
		token = strtok(NULL, " \t");
	}
	arguments[index] = NULL;

	return (arguments);
}
