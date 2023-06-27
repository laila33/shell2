#include "shell_.h"

/**
 * *strcpy_func1 - Copies string.
 * @s2: Destination string
 * @s1: Source
 *
 * Return: pointer to Destination
 */
char *strcpy_func1(char *s2, char *s1)
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
 * strdup_func1 - duplicate string.
 * @s: the string  duplicate it.
 *
 * Return: Pointer to the duplicated string
 */
char *strdup_func1(const char *s)
{
	int size = 0;
	char *result;

	if (s == NULL)
		return (NULL);
	while (*s++)
		size++;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	for (size++; size--;)
		result[size] = *--s;
	return (result);
}


/**
 * _putchar - write the character ch to stdout.
 * @ch: The char to print.
 *
 * Return: 1 or -1.
 */
int _putchar(char ch)
{
	static int j;
	static char buffer[WRITE__SIZE];

	if (ch == BUF_FLUSH || j >= WRITE__SIZE)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[j++] = ch;
	return (1);
}


/**
 * puts_func - print string.
 * @s: the string to be printed
 *
 * Return: None
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
