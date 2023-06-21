#include "shell_.h"

/**
 **strncpy_2 - copy the  string.
 *@s2: destination string to copy.
 *
 *@s1: the source string.
 *
 *@num: the number  of characters to copy.
 *
 *Return: string after concatenated.
 */
char *strncpy_2(char *s2, char *s1, int num)
{
	int x, y = 0;
	char *c = s2;

	x = 0;

	while (s1[x] != '\0' && x < num - 1)
	{
		s2[x] = s1[x];
		x++;
	}

	if (x < num)
	{
		x = y;
		while (y < num)
		{
			s2[y] = '\0';
			y++;
		}
	}
	return (c);
}


/**
 **strncat_2 - concatenate two strings.
 *
 *
 *@s2: first string.
 *
 *@s1: the second string.
 *@num: the number of bytes to  use.
 *
 *Return: concatenated string.
 */
char *strncat_2(char *s2, char *s1, int num)
{
	int x = 0, y = 0;
	char *c = s2;


	while (s2[x] != '\0')
		x++;
	while (s1[y] != '\0' && y < num)
	{
		s2[x] = s1[y];
		x++;
		y++;
	}
	if (y < num)
		s2[x] = '\0';
	return (c);
}





/**
 **strchr_2 - find  character in  string.
 *
 *@s1: the string to search in.
 *
 *@charr: character to find.
 *
 *Return:  pointer to the memory area s1.
 */
char *strchr_2(char *s1, char charr)
{
	do {
		if (*s1 == charr)
			return (s1);
	} while (*s1++ != '\0');

	return (NULL);
}
