#include "shell_.h"

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
	char **m = x;

	if (!x)
		return;
	while (*x)
		free(*x++);
	free(m);
}

/**
 * find_str - reallocates a sizee of memory
 * @x: pointer to previous malloc'ated block
 * @oldd: size of byte of previous block.
 * @neww: size of byte of a new block.
 *
 * Return: Pointer to BLOCJ IN MEMORY.
 */
void *find_str(void *x, unsigned int oldd, unsigned int neww)
{
	char *a;

	if (!x)
		return (malloc(neww));
	if (!neww)
		return (free(x), NULL);
	if (neww == oldd)
		return (x);

	a = malloc(neww);
	if (!a)
		return (NULL);

	oldd = oldd < neww ? oldd : neww;
	while (oldd--)
		a[oldd] = ((char *)x)[oldd];
	free(x);
	return (a);
}
