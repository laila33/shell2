#include "shell_.h"


/**
 * strlen_func - Return length of string.
 *
 * @stringg:  string to find it length.
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
 * strcmp_func - Find lexicogarphic comparison of two strings.
 * @s: First string.
 *
 * @ss: Second string.
 *
 * Return: Negative if s < ss, Positive if s > ss, Zero if s == ss
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
 * strcat_func - concatenate two strings.
 *
 * @s2: THE destination buffer.
 *
 * @s1:  THE source buffer.
 *
 * Return: Pointer to destination.
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
 * @string: String to search.
 *
 * @substring: the substring to find.
 *
 * Return: Address of next char of stringg , NULL
 */
char *start_with_func(const char *string, const char *substring)
{
	while (*substring)
		if (*substring++ != *string++)
			return (NULL);
	return ((char *)string);
}



