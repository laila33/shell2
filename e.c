#include "shell_.h"

/**
 * env_fun - print current environment
 *
 * @info: struct
 *
 * Return: 0
*/

int env_fun(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * getenv_fun - get value of env
 *
 * @info: struct
 * @n: env name
 *
 * Return: value
*/

char *getenv_fun(info_t *info, const char *n)
{
	my_list_t *node = info->env;
	char *a;

	while (node)
	{
		a = starts_with_func(node->s, n);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenv_f - new env variable
 *
 * @info: struct
 *
 * Return: 0
*/

int setenv_f(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Invaild num of arguments\n");
		return (1);
	}
	if (setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenv_f - remove env variable
 *
 * @info: struct
 *
 * Return: 0
*/

int unsetenv_f(info_t *info)
{
	int l;

	if (info->argc == 1)
	{
		_eputs("Too arguments.\n");
		return (1);
	}
	for (l = 1; l <= info->argc; l++)
		unsetenv(info, info->argv[l]);

	return (0);
}

/**
 * penv_list - populates env list
 *
 * @info: struct
 *
 * Return: 0
*/

int penv_list(info_t *info)
{
	my_list_t *node = NULL;
	size_t l;

	for (l = 0; env[l]; l++)
		add_node_end(&node, env[l], 0);
	info->env = node;
	return (0);
}
