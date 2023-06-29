#include "shell_.h"
int help_fun(info_tt *info);
int exit_fun(info_tt *info);
int cd_fun(info_tt *info);




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


	puts_func("The help command is not yet available.\n");


	if (0)
		puts_func(*arg_arr);
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
	char *sg, *dr, buf[1024];
	int chdir_ret;

	sg = getcwd(buf, 1024);
	if (!sg)
		puts_func("Error: Unable to retrieve current directory.\n");
	if (!info->arg_v[1])
	{
		dr = getenv_fun(info, "HOME=");
		if (!dr)
			chdir_ret =
				chdir((dr = getenv_fun(info, "PWD=")) ? dr : "/");
		else
			chdir_ret = chdir(dr);
	}
	else if (strcmp_func(info->arg_v[1], "-") == 0)
	{
		if (!getenv_fun(info, "OLDPWD="))
		{
			puts_func(sg);
			_putchar('\n');
			return (1);
		}
		puts_func(getenv_fun(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dr = getenv_fun(info, "OLDPWD=")) ? dr : "/");
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
		__setenv(info, "OLDPWD", getenv_fun(info, "PWD="));
		__setenv(info, "PWD", getcwd(buf, 1024));
	}
	return (0);
}
