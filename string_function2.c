#include"shell_.h"
/**
 * strcpy_func - copie string.
 *
 * @s2: the destination.
 *
 * @s1: the source.
 *
 * Return: pointer to destination.
 */
char *strcpy_func(char *s2, char *s1)
{
	int j = 0;

	if (s2 == s1 || s1 == 0)
		return (s2);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = 0;
	return (s2);
}



/**
 * strdup_func - duplicates  string.
 *
 * @s1:  string to duplicate.
 *
 *
 * Return: pointer to the duplicated string.
 */

char *strdup_func(const char *s1)
{
	int len = 0;
	char *s2;

	if (s1 == NULL)
		return (NULL);
	while (*s1++)
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	for (len++; len--;)
		s2[len] = *--s1;
	return (s2);
}



/**
 * puts_func - prints  input string.
 *
 * @s: the string to print.
 *
 * Return: Nothing.
 */
void puts_func(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		_putchar(s[j]);
		j++;
	}
}




/**
 * _putchar - write the character a to stdout.
 *
 * @a: The character to be printed.
 *
 *
 * Return: 1 or -1 or errno is set appropriately.
 */
int _putchar(char a)
{
	static int j;
	static char buffer[WRITE__SIZE];

	if (a == _FLUSH || j >= WRITE__SIZE)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (a != _FLUSH)
		buffer[j++] = a;
	return (1);
}




