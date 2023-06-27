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

int ischain_fun(info_tt *info, char *buf, size_t *p)
{
	size_t n = *p;

	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_type = CMD__OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_type = CMD__AND;
	}
	else if (buf[n] == ';')
	{
		buf[n] = 0;
		info->cmd_type = CMD__CHAIN;
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

void checkchain_fun(info_tt *info, char *buf, size_t *p, size_t s, size_t l)
{
	size_t n = *p;

	if (info->cmd_type == CMD__AND)
	{
		if (info->statuss)
		{
			buf[s] = 0;
			n = l;
		}
	}
	if (info->cmd_type == CMD__OR)
	{
		if (!info->statuss)
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

int repalias_fun(info_tt *info)
{
	int x;
	my_list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = start_node(info->alias, info->arg_v[0], '=');
		if (!node)
			return (0);
		free(info->arg_v[0]);
		p = strchr_func2(node->s, '=');
		if (!p)
			return (0);
		p = strdup_func1(p + 1);
		if (!p)
			return (0);
		info->arg_v[0] = p;
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

int repvars_fun(info_tt *info)
{
	int n = 0;
	my_list_t *node;

	for (n = 0; info->arg_v[n]; n++)
	{
		if (info->arg_v[n][0] != '$' || !info->arg_v[n][1])
			continue;

		if (!strcmp_func(info->arg_v[n], "$?"))
		{
			repstring_fun(&(info->arg_v[n]),
					strdup_func1(convert_d(info->statuss, 10, 0)));
			continue;
		}
		if (!strcmp_func(info->arg_v[n], "$$"))
		{
			repstring_fun(&(info->arg_v[n]),
					strdup_func1(convert_d(getpid(), 10, 0)));
			continue;
		}
		node = start_node(info->env, &(info->env[n][1]), '=');
		if (node)
		{
			repstring_fun(&(info->arg_v[n]),
					strdup_func1(strchr_func2(node->s, '=') + 1));
			continue;
		}
		repstring_fun(&info->arg_v[n], strdup_func1(""));
	}
	return (0);
}
