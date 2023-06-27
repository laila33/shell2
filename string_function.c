#include "shell_.h"

/**
 * strlen_func - return size of string.
 * @ss:string it's length to fund.
 *
 * Return: Size of string
 */
int strlen_func(char *ss)
{
	int j = 0;

	if (!ss)
		return (0);

	while (*ss++)
		j++;
	return (j);
}

/**
 * strcmp_func -lexicogarphic comparison of two strings.
 * @src:first string
 * @dest:second strang
 *
 * Return: Negative if s1 < s2, Positive if s1 > s2 OR Zero if s1 == s2
 */
int strcmp_func(char *src, char *dest)
{
	while (*src && *dest)
	{
		if (*src != *dest)
			return (*src - *dest);
		src++;
		dest++;
	}
	if (*src == *dest)
		return (0);
	else
		return (*src < *dest ? -1 : 1);
}

/**
 * starts_with_func - Check if S2 start with S1.
 * @s1: String to search
 * @s2: Substring to find
 *
 * Return: Address of next CGARACHTER of s1 or NULL
 */
char *starts_with_func(const char *s1, const char *s2)
{
	while (*s2)
		if (*s2++ != *s1++)
			return (NULL);
	return ((char *)s1);
}

/**
 * strcat_func - concatenate two strings.
 * @ss:Destination buffer
 * @s: Source buffer
 *
 * Return: Pointer to Destination buffer.
 */
char *strcat_func(char *ss, char *s)
{
	char *result = ss;

	while (*ss)
		ss++;
	while (*s)
		*ss++ = *s++;
	*ss = *s;
	return (result);
}



