#include "shell.h"
/**
 * my_strcat - Adds the content of source string to destination string
 * @destination: First string
 * @source: Second string
 * Return: Pointer to the resulting string (destination)
 */
char *my_strcat(char *destination, char *source)
{
	int src_len = 0, dest_len = 0, index;

	while (source[src_len] != '\0')
	{
		src_len++;
	}
	while (destination[dest_len] != '\0')
	{
		dest_len++;
	}
	for (index = 0; index < src_len; index++)
	{
		destination[dest_len + index] = source[index];
	}
	destination[dest_len + src_len] = '\0';

	return (destination);
}
