#include "shell_.h"

/**
 * env_fun - print current environment
 *
 * @info: struct
 *
 * Return: 0
*/

int env_fun(info_tt *info)
{
	put_liststr(info->env);
	return (0);
}

/**
 * getenv_fun - get value of env
 *
 * @info: struct
 * @nv: env name
 *
 * Return: value
*/

char *getenv_fun(info_tt *info, const char *nv)
{
	my_list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with_func(node->s, nv);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenv_fun - new env variable
 *
 * @info: struct
 *
 * Return: 0
*/

int setenv_fun(info_tt *info)
{
	if (info->arg_c != 3)
	{
		eputs_func("Invaild num of arguments\n");
		return (1);
	}
	if (__setenv(info, info->arg_v[1], info->arg_v[2]))
		return (0);
	return (1);
}

/**
 * unsetenv_fun - remove env variable
 *
 * @info: struct
 *
 * Return: 0
*/

int unsetenv_fun(info_tt *info)
{
	int m;

	if (info->arg_c == 1)
	{
		eputs_func("Too arguments.\n");
		return (1);
	}
	for (m = 1; m <= info->arg_c; m++)
		__unsetenv(info, info->arg_v[m]);

	return (0);
}

/**
 * popenv_list - populates env list
 *
 * @info: struct
 *
 * Return: 0
*/

int popenv_list(info_tt *info)
{
	my_list_t *node = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
	insert_node(&node, environ[m], 0);
	info->env = node;
	return (0);
}
