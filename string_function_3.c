#include "shell.h"

char *strncpy_func2(char *s2, char *s1, int num);
char *strncat_func2(char *s2, char *s1, int num);
char *strchr_func2(char *a, char ch);
/**
 **strncpy_func2 - copies a string
 *@s2: Destination string to be copied IN.
 *@s1:Source string
 *@num: Numberof chars to copy.
 *Return: Concatenated string.
 */
char *strncpy_func2(char *s2, char *s1, int num)
{
	int x, y;
	char *a = s2;

	x = 0;
	while (s1[x] != '\0' && x < num - 1)
	{
		s2[x] = s1[x];
		x++;
	}
	if (x < num)
	{
		y = x;
		while (y < num)
		{
			s2[y] = '\0';
			y++;
		}
	}
	return (a);
}

/**
 **strncat_func2 - Concatenate two strings.
 *@s2: First string
 *@s1: Second string
 *@num: numbr of bytes to be maximally used.
 *Return: Concatenated string
 */
char *strncat_func2(char *s2, char *s1, int num)
{
	int x, y;
	char *a = s2;

	x = 0;
	y = 0;
	while (s2[x] != '\0')
		x++;
	while (s1[y] != '\0' && y < num)
	{
		s2[y] = s1[y];
		x++;
		y++;
	}
	if (y < num)
		s2[x] = '\0';
	return (a);
}

/**
 **strchr_func2 - find char in string.
 *@a:String to be parsed
 *@ch: char to find
 *Return: a is pointer to  memory area a
 */
char *strchr_func2(char *a, char ch)
{
	do {
		if (*a == ch)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
