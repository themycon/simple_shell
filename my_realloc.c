#include "shell.h"

/**
 * my_realloc - reallocates a block of memory
 * @ptr: pointer to previously allocated mem block
 * @old_size: size of the previous allocated mem block
 * @new_size: new byte size of new mem block
 *
 * Return: pointer to the reallocated mem block.
 */
void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new_ptr;
	size_t i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < old_size && i < new_size; i++)
	{
		new_ptr[i] = ((char *)ptr)[i];
	}

	free(ptr);
	return (new_ptr);
}
