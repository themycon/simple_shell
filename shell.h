#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

extern char **environ;  /* Declaration of the environ variable */

void handle_eof(void);
ssize_t read_input(char **input_line, size_t *buffer_size);
char **parse_input(char *input_line);
void execute_command(char **arguments);
size_t my_strlen(const char *s);
char *my_strcpy(char *destination, const char *source);
char *my_strcat(char *destination, char *source);
char *my_strncat(char *destination, const char *source, size_t num);
char *find_in_path(char *command);
int my_strcmp(const char *, const char *);
char *my_get_env(const char *var_name);
int my_strncmp(const char *s1, const char *s2, size_t n);
	
#endif /* SHELL_H */
