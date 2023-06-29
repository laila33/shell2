#include "shell_.h"
ssize_t inputbuf_fun(info_tt *info, char **buf, size_t *l);
ssize_t getinput_fun(info_tt *info);
void siginthandler_fun(__attribute__((unused))int snum);
ssize_t readbuf_fun(info_tt *info, char *buf, size_t *sz);
int getline_fun(info_tt *info, char **ptr, size_t *length);


/**
 * inputbuf_fun - buffer chain command
 *
 * @info: struct
 * @buf: address
 * @l: address
 *
 * Return: bytes
*/

ssize_t inputbuf_fun(info_tt *info, char **buf, size_t *l)
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
		i = getline_fun(info, buf, &len);
#endif
		if (i > 0)
		{
			if ((*buf)[i - 1] == '\n')
			{
				(*buf)[i - 1] = '\0';
				i--;
			}
			info->lcount_ch = 1;
			delete_message(*buf);
			bhistoryl(info, *buf, info->historycount++);
			{
				*l = i;
				info->cmd_buff = buf;
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

ssize_t getinput_fun(info_tt *info)
{
	static char *buf;
	static size_t r, n, l;
	ssize_t i = 0;
	char **buf_c = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	i = inputbuf_fun(info, &buf, &l);
	if (i == -1)
		return (-1);
	if (l)
	{
		n = r;
		p = buf + r;

		checkchain_fun(info, buf, &n, r, l);
		while (n < l)
		{
			if (ischain_fun(info, buf, &n))
				break;
			n++;
		}

		r = n + 1;
		if (r >= l)
		{
			r = l = 0;
			info->cmd_type = CMD__NORM;
		}

		*buf_c = p;
		return (strlen_func(p));
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
	puts_func("\n");
	puts_func("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * readbuf_fun - read buffer
 *
 * @info: struct
 * @buf: buffer
 * @sz: size
 *
 * Return: x
*/

ssize_t readbuf_fun(info_tt *info, char *buf, size_t *sz)
{
	ssize_t x = 0;

	if (*sz)
		return (0);
	x = read(info->readf, buf, READ__SIZE);
	if (x >= 0)
		*sz = x;
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

int getline_fun(info_tt *info, char **ptr, size_t *length)
{
	static char buf[READ__SIZE];
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

	n = strchr_func2(buf + j, '\n');
	x = n ? 1 + (unsigned int)(n - buf) : len;
	newp = find_str(p, z, z ? z + x : x + 1);
	if (!newp)
		return (p ? free(p), -1 : -1);

	if (z)
		strncat_func2(newp, buf + j, x - j);
	else
		strncpy_func2(newp, buf + j, x - j + 1);

	z += x - j;
	j = x;
	p = newp;

	if (length)
		*length = z;
	*ptr = p;
	return (z);
}
