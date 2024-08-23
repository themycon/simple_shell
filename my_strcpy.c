#include "shell.h"

/**
 * my_strcpy - copy string
 * @destination: destination string argumnet
 * @source: source argument
 * Return: string value
 */
char *my_strcpy(char *destination, const char *source)
{
	int index, length = 0;

	while (source[length] != '\0')
	{
		length++;
	}
	for (index = 0; index < length; index++)
	{
		destination[index] = source[index];
	}
	destination[index] = '\0';
	return (destination);
}
