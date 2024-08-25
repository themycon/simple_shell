#include "shell.h"

/**
 * my_strncmp - Compares two strings upto a specified number of characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters,
 *         a negative value if s1 is less than s2,
 *         or a positive value if s1 is greater than s2.
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{

	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	s1++;
	s2++;
	n--;
	}

	if (n == 0)
		return (0);

	return ((unsigned char)*s1 - (unsigned char)*s2);
}
