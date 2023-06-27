#include "shell_.h"

/**
 *eputs_func - print input string.
 *
 *@s: the string to  print.
 *
 * Return: Nothing
 */
void eputs_func(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		Eput(s[j]);
		j++;
	}
}

/**
 * Eput - write the char ch to stderr.
 * @ch: The character to print.
 *
 * Return: 1 or -1.
 */
int Eput(char ch)
{
	static int j;
	static char buffer[WRITE__SIZE];

	if (ch == BUF_FLUSH || j >= WRITE__SIZE)
	{
		write(2, buffer, j);
		j = 0;
	}

	if (ch !=BUF_FLUSH)
		buffer[j++] = ch;
	return (1);
}



/**
 * putfd_func - write the char ch to given fd.
 * @ch: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: 1 or -1
 */
int putfd_func(char ch, int fd)
{
	static int j;
	static char buffer[WRITE__SIZE];

	if (ch == BUF_FLUSH || j >= WRITE__SIZE)
	{
		write(fd, buffer, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[j++] = ch;
	return (1);
}

/**
 *putsfd_print - prints an input string.
 * @s: the string to  print.
 * @fd: the filedescriptor to write .
 *
 * Return: the number of chars put.
 */
int putsfd_print(char *s, int fd)
{
	int j = 0;

	if (!s)
		return (0);
	while (*s)
	{
		j += putfd_func(*s++, fd);
	}
	return (j);
}
