#include "shell_.h"

/**
 * memset_func - fill memory with a constant thing.
 *
 * @src:  pointer to the specfic area.
 *
 * @th: byte to fill string src with.
 *
 * @num: the amount of bytes to filled.
 *
 * Return:  pointer to the memory area in string src.
 *
 */
char *memset_func(char *src, char th, unsigned int num)
{
	unsigned int j;

	for (j = 0; j < num; j++)
		src[j] = th;
	return (src);
}

/**
 * free_func - free  string of strings.
 *
 * @s: string of strings.
 */
void free_func(char **s)
{
	char **x = s;

	if (!s)
		return;
	while (*s)
		free(*s++);
	free(x);
}



/**
 * realloc_func - reallocates a space of memory.
 *
 * @str: pointer to previous mallocated block.
 *
 * @oldd: size of previous block.
 *
 * @neww:  size of new block
 *
 * Return: pointer to old block.
 */
void *realloc_func(void *str, unsigned int oldd, unsigned int neww)
{
	char *x;

	if (!str)
		return (malloc(neww));
	if (!neww)
		return (free(str), NULL);
	if (neww == oldd)
		return (str);

	x = malloc(neww);
	if (!x)
		return (NULL);

	oldd = oldd < neww ? oldd : neww;
	while (oldd--)
		x[oldd] = ((char *)str)[oldd];
	free(str);
	return (x);
}


