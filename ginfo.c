#include "shell_.h"

/**
 * clearinfo_fun - initializes info_t
 *
 * @info: struct
*/

void clearinfo_fun(info_tt *info)
{
	info->input = NULL;
	info->arg_v = NULL;
	info->arg = NULL;
	info->arg_c = 0;
}

/**
 * setinfo_fun - initializes info_t
 *
 * @info: struct
 * @at: arg vector
*/

void setinfo_fun(info_tt *info, char **at)
{
	int n = 0;

	info->filename = at[0];
	if (info->arg)
	{
		info->arg_v = strtow_func(info->arg, "\t");
		if (!info->arg_v)
		{
			info->arg_v = malloc(sizeof(char *) * 2);
			if (info->arg_v)
			{
				info->arg_v[0] = strdup_func1(info->arg);
				info->arg_v[1] = NULL;
			}
		}
		for (n = 0; info->arg_v && info->arg_v[n]; n++)
			;
		info->arg_c = n;
		repalias(info);
		repvars(info);
	}
}

/**
 * freeinfo_fun - free info_t
 *
 * @info: struct
 * @f: free all fields
*/

void freeinfo_fun(info_tt *info, int f)
{
	free(info->arg_v);
	info->input = NULL;
	info->arg_v = NULL;

	if (f)
	{
		if (!info->cmd_buff)
			free(info->arg);
		if (info->the_history)
			free_linked(&(info->the_history));
		if (info->env)
			free_linked(&(info->env));
		if (info->alias)
			free_linked(&(info->alias));
		free_str(info->environ);
		info->environ = NULL;
		free_function((void **)info->cmd_buff);
		if (info->readf > 2)
			close(info->readf);
		_putcharr(BUF_FLUSH);
	}
}
