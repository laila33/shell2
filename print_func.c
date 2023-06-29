#include "shell_.h"
int convert_func(char *x);
void put_error(info_tt *info, char *str);
int _putt(int x, int fd);
char *convert_d(long int number, int on, int ch);
void delete_message(char *buf);

/**
 * convert_func - convert string into intger
 * @x: String to  convert it.
 * Return: 0 OR .
 */
int convert_func(char *x)
{
	int j = 0;
	unsigned long int t = 0;

	if (*x == '+')
		x++;
	for (j = 0; x[j] != '\0'; j++)
	{
		if (x[j] >= '0' && x[j] <= '9')
		{
			t *= 10;
			t += (x[j] - '0');
			if (t > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (t);
}

/**
 * put_error - Print message with error.
 * @info: Parameter and  return info struct
 * @str: String containe error type
 * Return: 0 OR -1.
 */
void put_error(info_tt *info, char *str)
{
	eputs_func(info->filename);
	eputs_func(": ");
	_putt(info->l_count, STDERR_FILENO);
	eputs_func(": ");
	eputs_func(info->arg_v[0]);
	eputs_func(": ");
	eputs_func(str);
}

/**
 * _putt -print decimal  number on base 10
 * @x: the input
 * @fd: the filedescriptor to write to
 *
 * Return: Number of char print
 */
int _putt(int x, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, cntr = 0;
	unsigned int _sss_, now;

	if (fd == STDERR_FILENO)
		__putchar = eputchar_func;
	if (x < 0)
	{
		_sss_ = -x;
		__putchar('-');
		cntr++;
	}
	else
		_sss_ = x;
	now = _sss_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_sss_ / j)
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
 * convert_d - Converters function and clone of itoa.
 * @number: number
 * @on: base
 * @ch: argument ch
 *
 * Return: String.
 */
char *convert_d(long int number, int on, int ch)
{
	static char *x;
	static char buf[50];
	char s = 0;
	char *str;
	unsigned long a = number;

	if (!(ch & CONVERT_UNSIGNED) && number < 0)
	{
		a = -number;
		s = '-';

	}
	x = ch & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buf[49];
	*str = '\0';

	do	{
		*--str = x[a % on];
		a /= on;
	} while (a != 0);

	if (s)
		*--str = s;
	return (str);
}

/**
 * delete_message -  Replace first instance of '#' with '\0'
 * @buf: Addressstring to modify IT.
 *
 * Return:  0.
 */
void delete_message(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
