#include "shell.h"
/**
 * my_strlen - length of a string
 * @str: string
 * Return: length of a string
 */

size_t my_strlen(const char *str)
{
	size_t index = 0;

	while (*(str + index) != '\0')
	{
		index++;
	}
	return (index);
}
