#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;  /* Declaration of the environ variable */

void handle_eof(void);
ssize_t read_input(char **input_line, size_t *buffer_size);
char **parse_input(char *input_line);
void execute_command(char **arguments);
size_t my_strlen(const char *str);
char *my_strcpy(char *destination, const char *source);
char *my_strcat(char *destination, const char *source);

#endif /* SHELL_H */
