#include "shell_.h"

/**
 * ischain_fun - test if char in buffer
 *
 * @info: struct
 * @buf: buf
 * @p: address
 *
 * Return: 1 if chain delimeter else 0
*/

int ischain_fun(info_t *info, char *buf, size_t *p)
{
	size_t n = *p;

	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[n] == ';')
	{
		buf[n] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = n;
	return (1);
}

/**
 * checkchain_fun - checks
 *
 * @info: struct
 * @buf: buffer
 * @p: address
 * @s: start position in buf
 * @l: length
 *
 * Return: void
*/

void checkchain_fun(info_t *info, char *buf, size_t *p, size_t s, size_t l)
{
	size_t n = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[s] = 0;
			n = l;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[s] = 0;
			n = l;
		}
	}
	*p = n;
}

/**
 * repalias_fun - replace alias
 *
 * @info: struct
 *
 * Return: 1 if replaced else 0
*/

int repalias_fun(info_t *info)
{
	int x;
	my_list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = strchr_2(node->s, '=');
		if (!p)
			return (0);
		p = *strdup_func(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * repstring_fun - replace string
 *
 * @oldd: address
 * @neww: new string
 *
 * Return: 1 if replaced else 0
*/

int repstring_fun(char **oldd, char *neww)
{
	free(*oldd);
	*oldd = neww;
	return (1);
}

/**
 * repvars_fun - replace vars
 *
 * @info: struct
 *
 * Return: 1 if replaced else 0
*/

int repvars_fun(info_t *info)
{
	int n = 0;
	my_list_t *node;

	for (n = 0; info->argv[n]; n++)
	{
		if (info->argv[n][0] != '$' || !info->argv[n][1])
			continue;

		if (!strcmp_func(info->argv[n], "$?"))
		{
			repstring_fun(&(info->argv[n]),
					*strdup_func(convert_3(info->status, 10, 0)));
			continue;
		}
		if (!strcmp_func(info->argv[n], "$$"))
		{
			repstring_fun(&(info->argv[n]),
					*strdup_func(convert_3(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->[n][1], '=');
		if (node)
		{
			repstring_fun(&(info->argv[n]),
					*strdup_func(strchr_2(node->s, '=') + 1));
			continue;
		}
		repstring_fun(&info->argv[n], *strdup_func(""));
	}
	return (0);
}
