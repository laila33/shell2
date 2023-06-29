<<<<<<< HEAD
#include "shell.h"
=======
#include "shell_.h"
char **strtow_func(char *str, char *copy);

char **strtow_func2(char *str, char copy);
>>>>>>> 0c6498174d79ac3f6e640b3c70a8d1c2bbc5cfed

/**
 * **strtow_func - split string into words Repeat delimiters will be ignore.
 *
 * @str: the input string.
 *
 * @copy: the delimeter string
 * Return: a pointer to an array of strings or NULL.
 *
 */

char **strtow_func(char *str, char *copy)
{
	int i, j, x, y, c = 0;
	char **a;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!copy)
		copy = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!isdelim_fun(str[i], copy) &&
				(isdelim_fun(str[i + 1], copy) || !str[i + 1]))
			c++;

	if (c == 0)
		return (NULL);
	a = malloc((1 + c) * sizeof(char *));
	if (!a)
		return (NULL);
	for (i = 0, j = 0; j < c; j++)
	{
		while (isdelim_fun(str[i], copy))
			i++;
		x = 0;
		while (!isdelim_fun(str[i + x], copy) && str[i + x])
			x++;
		a[j] = malloc((x + 1) * sizeof(char));
		if (!a[j])
		{
			for (x = 0; x < j; x++)
				free(a[x]);
			free(a);
			return (NULL);
		}
		for (y = 0; y < x; y++)
			a[j][y] = str[i++];
		a[j][y] = 0;
	}
	a[j] = NULL;
	return (a);
}

/**
 * **strtow_func2 - split a string into words only.
 *
 * @str: the input string.
 *
 * @copy: the delimeter.
 *
 * Return: Pointer to an array of strings:WQ
 *  or NULL.
 */
char **strtow_func2(char *str, char copy)
{
	int i, j, x, y,  c = 0;
	char **a;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != copy && str[i + 1] == copy) ||
				    (str[i] != copy && !str[i + 1]) || str[i + 1] == copy)
			c++;
	if (c == 0)
		return (NULL);
	a = malloc((1 + c) * sizeof(char *));
	if (!a)
		return (NULL);
	for (i = 0, j = 0; j < c; j++)
	{
		while (str[i] == copy && str[i] != copy)
			i++;
		x = 0;
		while (str[i + x] != copy && str[i + x] && str[i + x] != copy)
			x++;
		a[j] = malloc((x + 1) * sizeof(char));
		if (!a[j])
		{
			for (x = 0; x < j; x++)
				free(a[x]);
			free(a);
			return (NULL);
		}
		for (y = 0; y < x; y++)
			a[j][y] = str[i++];
		a[j][y] = 0;
	}
	a[j] = NULL;
	return (a);
}


