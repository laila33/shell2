#include "shell.h"

/**
 * **_strtow_func - split string into words and  Repeat delimiters be ignor.
 *
 * @c: the input string.
 *
 * @copy: the delimeter string.
 *
 * Return: a pointer to  array of strings or NULL.
 *
 */

char **_strtow_func(char *c, char *copy)
{
	int x, y, a, b, word = 0;
	char **s1;

	if (c == NULL || c[0] == 0)
		return (NULL);
	if (!copy)
		copy = " ";
	for (x = 0; c[x] != '\0'; x++)
		if (!is_delim(str[x], copy) && (is_delim(str[x + 1], copy) || !c[x + 1]))
			word++;

	if (word == 0)
		return (NULL);
	s1 = malloc((1 + word) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < word; y++)
	{
		while (is_delim(str[x], copy))
			x++;
		a = 0;
		while (!is_delim(str[x + a], d) && str[x + a])
			a++;
		s[y] = malloc((a + 1) * sizeof(char));
		if (!s1[y])
		{
			for (a = 0; a < y; a++)
				free(s[a]);
			free(s1);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			s1[y][b] = c[x++];
		s1[y][b] = 0;
	}
	s1[y] = NULL;
	return (s1);
}
/**
 * **strtow_func2 - splits a string into words.
 *
 * c: the input string.
 * @copy: the delimeter.
 *
 * Return: a pointer to an array of strings or NULL.
 */

char **strtow_function2(char *str, char copy)
{
	int x, y, a, b, word = 0;
	char **s1;

	if (c == NULL || c[0] == 0)
		return (NULL);
	for (x = 0; c[x]!= '\0'; x++)
		if ((c[x] != copy && x[x + 1] == copy) ||
				    (c[x] != copy && !c[x + 1]) || x[x + 1] == copy)
			word++;
	if (word == 0)
		return (NULL);
	s1 = malloc((1 + word) * sizeof(char *));
	if (!s1)
		return (NULL);
	for (x = 0, y = 0; y < word; y++)
	{
		while (c[x] == copy && c[x] != copy)
			x++;
		a = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			a++;
		s1[j] = malloc((a + 1) * sizeof(char));
		if (!s1[y])
		{
			for (y = 0; a < y; a++)
				free(s[a]);
			free(s1);
			return (NULL);
		}
		for (b = 0; b < k; b++)
			s1[y][b] = c[x++];
		s[y][b] = 0;
	}
	s1[y] = NULL;
	return (s1);
}


