#include "shell_.h"
char *memset_func(char *m, char num, unsigned int am);
void free_str(char **x);
void *find_str(void *ptr, unsigned int old_s, unsigned int new_s);

/**
 **memset_func - fill memory with a number of bytes.
 *@m: Pointer to the area in memory.
 *@num: ByteS to PUT *m with.
 *@am: NUMBER  of bytes to be filled.
 *Return: (m)Pointer to the memory m.
 */
char *memset_func(char *m, char num, unsigned int am)
{
	unsigned int j;

	for (j = 0; j < am; j++)
		m[j] = num;
	return (m);
}

/**
 * free_str - free of strings
 * @x: String of (strings).
 */
void free_str(char **x)
{
	char **l = x;

	if (!x)
		return;
	while (*x)
		free(*x++);
	free(l);
}

/**
 * find_str - reallocates a sizee of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_s: size of byte of previous block.
 * @new_s: size of byte of a new block.
 *
 * Return: Pointer to BLOCJ IN MEMORY.
 */
void *find_str(void *ptr, unsigned int old_s, unsigned int new_s)
{
	char *p;

	if (!ptr)
		return (malloc(new_s));
	if (!new_s)
		return (free(ptr), NULL);
	if (new_s == old_s)
		return (ptr);

	p = malloc(new_s);
	if (!p)
		return (NULL);

	old_s = old_s < new_s ? old_s : new_s;
	while (old_s--)
		p[old_s] = ((char *)ptr)[old_s];
	free(ptr);
	return (p);
}
