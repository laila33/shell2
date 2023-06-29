#include "shell_.h"
void eputs_func(char *str);
int eputchar_func(char ch);
int putfd_func(char ch, int filed);
int putsfd_d(char *s, int filed);

/**
 *eputs_func - print input string.
 * @str: the string to print.
 *
 * Return: (Nothing)
 */
void eputs_func(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		eputchar_func(str[j]);
		j++;
	}
}

/**
 * eputchar_func - write the character ch to stderr.
 * @ch:character to print it.
 *
 * Return: 1 or-1.
 */
int eputchar_func(char ch)
{
	static int j;
	static char buf[WRITE__SIZE];

	if (ch == BUF_FLUSH || j >= WRITE__SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}

/**
 * putfd_func - write the character ch to given filed.
 * @ch:character to print it.
 * @filed:filedescriptor to write to.
 *
 * Return: 1 or -1.
 */
int putfd_func(char ch, int filed)
{
	static int j;
	static char buffer[WRITE__SIZE];

	if (ch == BUF_FLUSH || j >= WRITE__SIZE)
	{
		write(filed, buffer, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[j++] = ch;
	return (1);
}

/**
 *putsfd_d - print input string.
 * @s:string to print it.
 * @filed:filedescriptor to write to.
 *
 * Return: number of chars.
 */
int putsfd_d(char *s, int filed)
{
	int j = 0;

	if (!s)
		return (0);
	while (*s)
	{
		j += putfd_func(*s++, filed);
	}
	return (j);
}

