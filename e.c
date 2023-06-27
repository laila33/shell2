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
	put_liststr(info->environ);
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

char *getenv_fun(info_tt *info, const char *n)
{
	my_list_t *node = info->environ;
	char *p;

	while (node)
	{
		p = starts_with_func(node->s, n);
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
	int l;

	if (info->arg_c == 1)
	{
		eputs_func("Too arguments.\n");
		return (1);
	}
	for (l = 1; l <= info->arg_c; l++)
		__unsetenv(info, info->arg_v[l]);

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
	size_t l;

	for (l = 0; env[l]; l++)
<<<<<<< HEAD
		insert_node(&node, env[l], 0);
	info->env = node;
=======
		insert_end_node(&node, environ[l], 0);
	info->environ = node;
>>>>>>> 1216294cbe4fd65703a84a7a9aa6db29a5bd29dc
	return (0);
}
