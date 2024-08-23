#include "shell.h"
/**
 * my_strncpy - Copies n characters from the source string to destination
 * @destination: target
 * @source: source string
 * @num: integers to copy
 * Return: Pointer to the resulting string (destination)
 */
char *my_strncpy(char *destination, char *source, int num)
{
	int index;

	for (index = 0; index < num && source[index] != '\0'; index++)
	{
		destination[index] = source[index];
	}
	for (; index < num; index++)
	{
		destination[index] = '\0';
	}
	return (destination);
}
