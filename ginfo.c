#include "shell_.h"

/**
 * clearinfo_fun - initializes info_t
 *
 * @info: struct
*/

void clearinfo_fun(info_t *info)
{
	info->path = NULL;
	info->arg = NULL;
	info->arg = NULL;
	info->argc = 0;
}

/**
 * setinfo_fun - initializes info_t
 *
 * @info: struct
 * @a: arg vector
*/

void setinfo_fun(info_t *info, char **a)
{
	int n = 0;

	info->fname = a[0];
	if (info->arg)
	{
		info->argv = strtow_func(info->arg, "\t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = *strdup_func(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (n = 0; info->argv && info->argv[n]; n++)
			;
		info->argc = n;
		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * freeinfo_fun - free info_t
 *
 * @info: struct
 * @a: free all fields
*/

void freeinfo_fun(info_t *info, int a)
{
	free(info->argv);
	info->path = NULL;
	info->argv = NULL;

	if (a)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->history)
			free_list(&(info->history));
		if (info->env)
			free_list(&(info->env));
		if (info->alias)
			free_list(&(info->alias));
		free(info->environ);
		info->environ = NULL;

