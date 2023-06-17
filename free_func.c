#include "shell_.h"

/**
 * free_function - free pointer and let address equel null.
 *
 * @p: pointer address.
 *
 * Return: 1 or 0.
 */
int free_function(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
