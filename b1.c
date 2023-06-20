#include "shell_.h"

/**
 * history_fun - displays the history
 *
 * @info: structure
 *
 * Return: 0
*/

int history_fun(info_t *info)
{
	print_list(info->history);
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

int unsetalias_fun(info_t *info, char *s)
{
	char *a, b;
	int r;

	a = _strchr(s, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	r = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, s, -1)));
	*a = b;
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

int setalias_fun(info_t *info, char *s)
{
	char *a;

	a = _strchr(s, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unsetalias_fun(info, s));

	unsetalias_fun(info, s);
	return (add_node_end(&(info->alias), s, 0) == NULL);
}

/**
 * printalias_fun - print alias string
 *
 * @node: alias node
 *
 * Return: 0 success 1 if fail
*/

int printalias_fun(list_t *node)
{
	char *a = NULL, *l = NULL;

	if (node)
	{
		a = _strchr(node->s, '=');
		for (l = node->s; l <= a; l++)
			_putchar(*l);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
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

int alias_fun(info_t *info)
{
	int n = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printalias_fun(node);
			node = node->next;
		}
		return (0);
	}
	for (n = 1; info->argv[n]; n++)
	{
		a = _strchr(info->argv[n], '=');
		if (a)
			setalias_fun(info, info->argv[n]);
		else
			printalias_fun(node_starts_with(info->alias, info->argv[n], '='));
	}
	return (0);
}
