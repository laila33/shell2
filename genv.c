#include "shell_.h"

/**
 * getenv_f - returns string arr copy of our environ
 *
 * @info: struct
 *
 * Return: 0
*/

char **getenv_f(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * unsetenv_fun - remove env variable
 *
 * @info: struct
 * @v: string env var
 *
 * Return: 1 if delete else 0
*/

int unsetenv_fun(info_t *info, char *v)
{
	my_list_t *node = info->env;
	size_t n = 0;
	char *p;

	if (!node || !v)
		return (0);

	while (node)
	{
		p = starts_with(node->s, v);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), n);
			n = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		n++;
	}
	return (info->env_changed);
}

/**
 * setenv_fun - initialize new env var
 *
 * @info: struct
 * @v: string env var
 * @u: env var value
 *
 * Return: 0
*/

int setenv_fun(info_t *info, char *v, char *u)
{
	char *p;
	char *buf = NULL;
	my_list_t *node;

	if (!v || !u)
		return (0);
	buf = malloc(strlen_func(v) + strlen_func(u) + 2);
	if (!buf)
		return (1);
	*strcpy_func(buf, v);
	*strcat_func(buf, "=");
	*strcat_func(buf, u);
	node = info->env;
	while (node)
	{
		p = starts_with(node->s, v);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
