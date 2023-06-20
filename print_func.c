#include "shell_.h"

/**
 * convarte_ - convert a string to integer.
 *
 * @s1:  string to converte.
 *
 * Return: 0 , or -1.
 *
 */
int convarte_(char *s1)
{
	int j = 0;
	unsigned long int res = 0;

	if (*s1 == '+')
		s1++;
	for (j = 0;  s1[j] != '\0'; j++)
	{
		if (s1[j] >= '0' && s1[j] <= '9')
		{
			res *= 10;
			res += (s1[j] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}




/**
 * error_1 - print  error message.
 *
 * @detailes: the parameter and return info struct.
 *
 * @str: string contane error type.
 *
 * Return: 0 or-1 .
 *
 */
void error_1(info_t *detailes, char *str)
{
	eputs_func(detailes->fname);
	eputs_func(": ");
	print_func(detailes->line_count, STDERR_FILENO);
	eputs_func(": ");
	eputs_func(detailes->argv[0]);
	eputs_func(": ");
	eputs_func(str);
}



/**
 * print_func - function print decimal (integer) number base 10.
 *
 * @input_num: the input.
 *
 * @f_d: the file descriptor to write.
 *
 *
 * Return: number of characters printed.
 */
int print_func(int input_num, int f_d)
{
	int (*__putchar)(char) = _putchar;
	int j, cntr = 0;
	unsigned int res, now;

	if (f_d == STDERR_FILENO)
		__putchar = eputchar;
	if (input_num < 0)
	{
		res = -input_num;
		__putchar('-');
		cntr++;
	}
	else
		res = input_num;
	now = now;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (res / j)
		{
			__putchar('0' + now / j);
			cntr++;
		}
		now %= j;
	}
	__putchar('0' + now);
	cntr++;

	return (cntr);
}



/**
 * convert_3 - converter function clone of int to string.
 *
 * @num: number.
 *
 * @base: base.
 *
 * @ch: argument ch
 *
 * Return: string.
 */
char *convert_3(long int num, int base, int ch)
{
	static char *v;
	static char buf[50];
	char s = 0;
	char *str;
	unsigned long n = num;

	if (!(ch & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';

	}
	v = ch & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buf[49];
	*str = '\0';

	do	{
		*--str = v[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--str = s;
	return (str);
}

/**
 * remove_comments_message - function replaces first instance of '#' with '\0'.
 *
 * @buffer: address of the string to modify.
 *
 *
 * Return:  0;
 */
void remove_comments_message(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != '\0'; j++)
		if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
		{
			buffer[j] = '\0';
			break;
		}
}
