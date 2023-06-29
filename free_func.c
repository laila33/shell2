#include "shell.h"

/**
 * free_function - free pointer and let address equel null.
 *
 * @ptr: pointer address.
 *
 * Return: 1 or 0.
 */
int free_function(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
