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
 * strcmp_func -return comparison of two strangs.
 * @string1: first string.
 *
 * @string2: second string.
 *
 * return negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int strcmp_func(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
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



