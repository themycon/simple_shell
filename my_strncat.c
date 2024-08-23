#include "shell.h"
/**
 * my_strncat - Concantenates two strings where n num
 * of bytes are copied from src.
 * @destination: Pointer to destination string.
 * @source: Pointer to source string.
 * @num: num of chars to copy from source.
 *
 * Return: Pointer to destination string.
 */
char *my_strncat(char *destination, const char *source, size_t num)
{
	size_t dest_length = my_strlen(destination);
	size_t index;

	for (index = 0; index < num && source[index] != '\0'; index++)
		destination[dest_length + index] = source[index];

	destination[dest_length + index] = '\0';

	return (destination);
}
