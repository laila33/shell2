#include "shell_.h"

/**
 * getenviron_fun - returns string arr copy of our environ
 *
 * @info: struct
 *
 * Return: 0
*/

char **getenviron_fun(info_tt *info)
{
	if (!info->environ || info->env_ch)
	{
		info->environ = l_to_s(info->env);
		info->env_ch = 0;
	}
	return (info->environ);
}

/**
 * __unsetenv - remove env variable
 *
 * @info: struct
 * @v: string env var
 *
 * Return: 1 if delete else 0
*/

int __unsetenv(info_tt *info, char *v)
{
	my_list_t *node = info->env;
	size_t m = 0;
	char *p;

	if (!node || !v)
		return (0);

	while (node)
	{
		p = starts_with_func(node->s, v);
		if (p && *p == '=')
		{
			info->env_ch = delete_index(&(info->env), m);
			m = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		m++;
	}
	return (info->env_ch);
}

/**
 * __setenv - initialize new env var
 *
 * @info: struct
 * @v: string env var
 * @u: env var value
 *
 * Return: 0
*/

int __setenv(info_tt *info, char *v, char *u)
{
	char *p;
	char *buf = NULL;
	my_list_t *node;

	if (!v || !u)
		return (0);
	buf = malloc(strlen_func(v) + strlen_func(u) + 2);
	if (!buf)
		return (1);
	strcpy_func1(buf, v);
	strcat_func(buf, "=");
	strcat_func(buf, u);
	node = info->env;
	while (node)
	{
		p = starts_with_func(node->s, v);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			info->env_ch = 1;
			return (0);
		}
		node = node->next;
	}
	insert_node(&(info->env), buf, 0);
	free(buf);
	info->env_ch = 1;
	return (0);
}
