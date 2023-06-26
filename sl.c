#include "shell_.h"

/**
 * mshell - main shell loop
 *
 * @info: struct
 * @a: argument
 *
 * Return: 0 success else 1
*/

int mshell(info_t *info, char **a)
{
	ssize_t n = 0;
	int br = 0;

	while (n != -1 && br != -2)
	{
		clearinfo_fun(info);
		if (interactive_fun(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		n = getinput_fun(info);
		if (n != -1)
		{
			setinfo_fun(info, a);
			br = findbuilt_fun(info);
			if (br == -1)
				f_path(info);
		}
		else if (interactive_fun(info))
			_putchar('\n');
		freeinfo_fun(info, 0);
	}
	history_w(info);
	freeinfo_info(info, 1);

	if (!interactive_fun(info) && info->status)
		exit_fun(info->status);

	if (br == -2)
	{
		if (info->err_num == -1)
			exit_fun(info->status);
		exit_fun(info->err_num);
	}
	return (br);
}

/**
 * findbuilt_fun - find built command
 *
 * @info: struct
 *
 * Return: -1 not found, 0 success, 1 not success, 2 exit
*/

int findbuilt_fun(info_t *info)
{
	int n, br = -1;
	builttable builtt[] = {
		{"exit", exit_fun},
		{"env", env_fun},
		{"help", help_fun},
		{"history", history_fun},
		{"setenv", setenv_fun},
		{"unsetenv", unsetenv_fun},
		{"cd", cd_fun},
		{"alias", alias_fun},
		{NULL, NULL}
	};

	for (n = 0; builtt[n].type; n++)
		if (strcmp_func(info->argv[0], builtt[n].type) == 0)
		{
			info->line_count++;
			br = builtt[n].fun(info);
			break;
		}
	return (br);
}

