#include "shell.h"

/**
 * history_fun - displays the history
 *
 * @info: structure
 *
 * Return: 0
*/

int history_fun(info_tt *info)
{
	print_node(info->the_history);
	return (0);
}

/**
 * unsetalias_fun - unset alias to string
 *
 * @info: struct
 * @s: string
 *
 * Return: 0 success 1 if fail
*/

int unsetalias_fun(info_tt *info, char *s)
{
	char *p, b;
	int r;

	p = strchr_func2(s, '=');
	if (!p)
		return (1);
	b = *p;
	*p = 0;
	r = delete_index(&(info->alias),
			find_node_index(info->alias, start_node(info->alias, s, -1)));
	*p = b;
	return (r);
}

/**
 * setalias_fun - set alias to string
 *
 * @info: struct
 * @s: string
 *
 * Return: 0 success 1 if fail
*/

int setalias_fun(info_tt *info, char *s)
{
	char *p;

	p = strchr_func2(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsetalias_fun(info, s));

	unsetalias_fun(info, s);
	return (insert_node(&(info->alias), s, 0) == NULL);
}

/**
 * printalias_fun - print alias string
 *
 * @node: alias node
 *
 * Return: 0 success 1 if fail
*/

int printalias_fun(my_list_t *node)
{
	char *p = NULL, *l = NULL;

	if (node)
	{
		p = strchr_func2(node->s, '=');
		for (l = node->s; l <= p; l++)
			putchar(*l);
		putchar('\'');
		puts_func(p + 1);
		puts_func("'\n");
		return (0);
	}
	return (1);
}

/**
 * alias_fun - man alias
 *
 * @info: struct
 *
 * Return: 0
*/

int alias_fun(info_tt *info)
{
	int n = 0;
	char *p = NULL;
	my_list_t *node = NULL;

	if (info->arg_c == 1)
	{
		node = info->alias;
		while (node)
		{
			printalias_fun(node);
			node = node->next;
		}
		return (0);
	}
	for (n = 1; info->arg_v[n]; n++)
	{
		p = strchr_func2(info->arg_v[n], '=');
		if (p)
			setalias_fun(info, info->arg_v[n]);
		else
			printalias_fun(start_node(info->alias, info->arg_v[n], '='));
	}
	return (0);
}
