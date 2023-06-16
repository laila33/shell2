#include "shell_.h"

/**
 * interactive_fun - see if shell in interactive mode
 *
 * @info: address
 *
 * Return: 1 if in the mode 0 if not
*/

int interactive_fun(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delim_fun - check if char is delimeter
 *
 * @c: char to check
 * @d: delimeter string
 *
 * Return: 1 if delimeter 0 if not
*/

int delim_fun(char c, char *d)
{
	while (*d)
		if (*d++ == c)
			return (1);
	return (0);
}

/**
 * alpha_fun - check for alphabetic char
 *
 * @c: input
 *
 * Return: 1 if c is alpha 0 if not
*/

int alpha_fun(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * atoi_fun - convert string to int
 *
 * @s: string to convert
 *
 * Return: 0
*/

int atoi_fun(char *s)
{
	int n = 1, o = 0;

	if (*s == '-')
	{
		n = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		o = (o * 10) + (*s - '0');
		s++;
	}

	return (o * n);
}
