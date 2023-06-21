#include "shell_.h"


/**
 * strlen_func - returns the length of  string.
 *
 * @stringg: the string to find it length.
 *
 *
 * Return: length of string.
 *
 */
int strlen_func(char *stringg)
{
	int j = 0;

	if (!stringg)
		return (0);

	while (*stringg++)
		j++;
	return (j);
}




/**
 * strcmp_func -find lexicogarphic comparison of two strings.
 * @s: first string.
 *
 * @ss: second string.
 *
 * Return: negative if s < ss, positive if s > ss, zero if s == ss
 */

int strcmp_func(char *s, char *ss)
{
	while (*s && *ss)
	{
		if (*s != *ss)
			return (*s - *ss);
		s++;
		ss++;
	}
	if (*s == *ss)
		return (0);
	else
		return (*s < *ss ? -1 : 1);
}



/**
 * strcat_func - concatenates two strings.
 *
 * @s2:  destination buffer.
 *
 * @s1:  source buffer.
 *
 * Return: pointer to destination.
 *
 *
 */
char *strcat_func(char *s1, char *s2)
{
	char *result = s2;

	while (*s2)
		s2++;
	while (*s1)
		*s2++ = *s1++;
	*s2 = *s1;
	return (result);
}


/**
 * start_with_func - define if string start with substring.
 *
 * @string: string to search.
 *
 * @substring: the substring to find.
 *
 * Return: address of next char of stringg or NULL
 */
char *start_with_func(const char *string, const char *substring)
{
	while (*substring)
		if (*substring++ != *string++)
			return (NULL);
	return ((char *)string);
}



