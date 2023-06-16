#include "shell_.h"

/**
 * help_fun - change current dir of the process
 *
 * @info: structure
 *
 * Return: 0
*/

int help_fun(info_t *info)
{
	char **arg_arr = info->argv;

	_puts("The help command is recognized, but the functionality is not yet available.\n");
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

int exit_fun(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
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

int cd_fun(info_t *info)
{
	char *dir, buffer[1024];
	int chdr;

	char *current_dir = getcwd(buffer, 1024);

	if (!current_dir)
	{
		printf("Error: Unable to retrieve current directory.\n");
		return (1);
	}

	if (!info->argv[1])
	{
		dir = getenv("HOME");
		if (!dir)
			dir = getenv("PWD");
		chdr = chdir(dir ? dir : "/");
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (!dir)
		{
			printf("%s\n", current_dir);
			return (1);
		}
		printf("%s\n", dir);
		chdr = chdir(dir ? dir : "/");
	}
	else
	{
		chdr = chdir(info->argv[1]);
	}

	if (chdr == -1)
	{
		printf("Error: Failed to change directory to %s\n", info->argv[1]);
	}
	else
	{
		setenv("OLDPWD", current_dir, 1);
		setenv("PWD", getcwd(buffer, 1024), 1);
	}

	return (0);
}
