#include "shell_.h"

/**
 * help_fun - change current dir of the process
 *
 * @info: structure
 *
 * Return: 0
*/

int help_fun(info_tt *info)
{
	char **arg_arr = info->arg_v;

	_puts(" The help command is recognized,
			but the functionality is not yet available.\n");

	if (0)
		_puts(*arg_arr);
	return (0);
}

/**
 * exit_fun - exit from shell
 *
 * @info: structure
 *
 * Return: exit with status 0
*/

int exit_fun(info_tt *info)
{
	int exitcheck;
i
	if (info->arg_v[1])
	{
		exitcheck = convert_func(info->arg_v[1]);

		if (exitcheck == -1)
		{
			info->statuss = 2;
			put_error(info, "Illegal number: ");
			eputs_func(info->arg_v[1]);
			eputchar_func('\n');

			return (1);
		}
		info->err_num = convert_func(info->arg_v[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cd_fun - change current dir
 *
 * @info: structure
 *
 * Return: 0
*/

int cd_fun(info_tt *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("Error: Unable to retrieve current directory.\n");
	if (!info->arg_v[1])
	{
		dir = getenv_fun(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = getenv_fun(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp_func(info->arg_v[1], "-") == 0)
	{
		if (!getenv_fun(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv_fun(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = getenv_fun(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->arg_v[1]);
	if (chdir_ret == -1)
	{
		put_error(info, "Error: Failed to change directory to %s\n");
		eputs_func(info->arg_v[1]), eputchar_func('\n');
	}
	else
	{
		setenv(info, "OLDPWD", getenv_fun(info, "PWD="));
		setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
