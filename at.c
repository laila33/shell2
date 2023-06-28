#include "shell_.h"

/**
 * interactive_fun - see if shell in interactive mode
 *
 * @info: address
 *
 * Return: 1 if in the mode 0 if not
*/

int interactive_fun(info_tt *info)
{
	return (isatty(STDIN_FILENO) && info->readf <= 2);
}

/**
 * isdelim_fun - check if char is delimeter
 *
 * @h: char to check
 * @dm: delimeter string
 *
 * Return: 1 if delimeter 0 if not
*/

int isdelim_fun(char h, char *dm)
{
	while (*dm)
		if (*dm++ == h)
			return (1);
	return (0);
}

/**
 * isalpha_fun - check for alphabetic char
 *
 * @h: input
 *
 * Return: 1 if c is alpha 0 if not
*/

int isalpha_fun(int h)
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * atoi_fun - convert string to int
 *
 * @sg: string to convert
 *
 * Return: 0
*/

int atoi_fun(char *sg)
{
	int n, sign = 1, f = 0, out;
	unsigned int res = 0;

	for (n = 0;  sg[n] != '\0' && f != 2; n++)
	{
		if (sg[n] == '-')
			sign *= -1;

		if (sg[n] >= '0' && sg[n] <= '9')
		{
			f = 1;
			res *= 10;
			res += (sg[n] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		out = -res;
	else
		out = res;

	return (out);
}
