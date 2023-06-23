#include "shell_.h"

/**
 * eputchar_fun - print input string
 *
 * @s: string
*/

void eputchar_fun(char *s)
{
	int l = 0;

	if (!s)
		return;
	while (s[l] != '\0')
	{
		eputchar_fun(s[l]);
		l++;
	}
}

/**
 * eputs_fun - write char r to stderr
 *
 * @r: char
 *
 * Return: 0 success 1 if fail
*/

int eputs_fun(char r)
{
	static int l;
	static char buf[WRITE__SIZE];

	if (r == BUF_FLUSH || l >= WRITE__SIZE)
	{
		write(2, buf, l);
		l = 0;
	}
	if (r != BUF_FLUSH)
		buf[l++] = r;
	return (1);
}
void eputchar_fun(char r)
{
	putchar(r);
	return (0);
}

/**
 * putfd_fun - write char r to given fd
 *
 * @r: char
 * @fd: filedescriptor
 *
 * Return: 1 success -1 if fail
*/

int putfd_fun(char r, int fd)
{
	static int l;
	static char buf[WRITE__SIZE];

	if (r == BUF_FLUSH || l >= WRITE__SIZE)
	{
		write(fd, buf, l);
		l = 0;
	}
	if (r != BUF_FLUSH)
		BUF[l++] = r;
	return (1);
}

/**
 * putsfd_fun - print input string
 *
 * @s: string
 * @fd: filedescriptor
 *
 * Return: num of char
*/

int putsfd_fun(char *s, int fd)
{
	int l = 0;

	if (!s)
		return (0);
	while (*s)
	{
		l += putfd_fun(*s++, fd);
	}
	return (l);
}
