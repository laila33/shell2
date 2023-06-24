#include "shell_.h"

/**
 * inputbuf_fun - buffer chain command
 *
 * @info: struct
 * @buf: address
 * @l: address
 *
 * Return: bytes
*/

ssize_t inputbuf_fun(info_t *info, char **buf, size_t *l)
{
	ssize_t i = 0;
	size_t len = 0;

	if (!*l)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, siginthandler_fun);
#if USE_GETLINE
		i = getline(buf, &len, stdin);
#else
		i = _getline(info, buf, &len);
#endif
		if (i > 0)
		{
			if ((*buf)[i - 1] == '\n')
			{
				(*buf)[i - 1] = '\0';
				i--;
			}
			info->linecount_flag = 1;
			remove_comments_message(*buf);
			buildhistory_list(info, *buf, info->histcount++);
			{
				*l = i;
				info->cmd_buf = buf;
			}
		}
	}
	return (i);
}

/**
 * getinput_fun - get lines
 *
 * @info: struct
 *
 * Return: byte
*/

ssize_t getinput_fun(info_t *info)
{
	static char *buf;
	static size_t r, n, l;
	ssize_t i = 0;
	char **buf_c = &(info->arg), *c;

	_putchar(BUF_FLUSH);
	i = input_buf(info, &buf, &l);
	if (i == -1)
		return (-1);
	if (l)
	{
		n = r;
		c = buf + r;

		check_chain(info, buf, &n, r, l);
		while (n < l)
		{
			if (is_chain(info, buf, &n))
				break;
			n++;
		}

		r = n + 1;
		if (r >= l)
		{
			r = l = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_c = c;
		return (_strlen(c));
	}

	*buf_c = buf;
	return (i);
}

/**
 * siginthandler_fun - blocks ctrl-C
 *
 * @snum: signal num
 *
 * Return: void
*/

void siginthandler_fun(__attribute__((unused))int snum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * readbuf_fun - read buffer
 *
 * @info: struct
 * @buf: buffer
 * @s: size
 *
 * Return: x
*/

ssize_t readbuf_fun(info_t *info, char *buf, size_t *s)
{
	ssize_t x = 0;

	if (*s)
		return (0);
	x = read(info->readfd, buf, READ_BUF_SIZE);
	if (x >= 0)
		*s = x;
	return (x);
}

/**
 * getline_fun - get next line of input
 *
 * @info: struct
 * @ptr: address of pointer to buffer
 * @length: size
 *
 * Return: z
*/

int getline_fun(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, len;
	size_t x;
	ssize_t i = 0, z = 0;
	char *p = NULL, *newp = NULL, *n;

	p = *ptr;
	if (p && length)
		z = *length;
	if (j == len)
		j = len = 0;

	i = readbuf_fun(info, buf, &len);
	if (i == -1 || (i == 0 && len == 0))
		return (-1);

	n = _strchr(buf + j, '\n');
	x = n ? 1 + (unsigned int)(n - buf) : len;
	newp = _realloc(p, z, z ? z + x : x + 1);
	if (!newp)
		return (p ? free(p), -1 : -1);

	if (z)
		_strncat(newp, buf + j, x - j);
	else
		_strncpy(newp, buf + j, x - j + 1);

	z += x - j;
	j = x;
	p = newp;

	if (length)
		*length = z;
	*ptr = p;
	return (z);
}
