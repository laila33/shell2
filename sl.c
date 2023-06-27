#include "shell_.h"

/**
 * mshell - main shell loop
 *
 * @info: struct
 * @a: argument
 *
 * Return: 0 success else 1
*/

int mshell(info_tt *info, char **a)
{
	ssize_t n = 0;
	int br = 0;

	while (n != -1 && br != -2)
	{
		clearinfo_fun(info);
		if (interactive_fun(info))
			_puts("$ ");
		eputchar_func(BUF_FLUSH);
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

int findbuilt_fun(info_tt *info)
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





/**
 * git_cmd - find  command from  PATH.
 *
 * @info: the parameter and  return info struct.
 *
 * Return: (void)
 */
void git_cmd(info_t *info)
{
	char *input = NULL;
	int i, j;

	info->input = info->argv[0];
	if (info->lcount_ch == 1)
	{
		info->l_count++;
		info->lcount_ch = 0;
	}
	for (i = 0, j = 0; info->arg[i]; i++)
		if (!isdelim_func(info->arg[i], " \t\n"))
			j++;
	if (!j)
		return;

	input = f_path(info, getenv_func(info, "PATH="), info->argv[0]);
	if (input)
	{
		info->input = input;
		f_cmd(info);
	}
	else
	{
		if ((interactive_fun(info) || getenv_fun(info, "PATH=")
			|| info->argv[0][0] == '/') && if_cmd(info, info->argv[0]))
			f_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			error_1(info, "not found\n");
		}
	}
}






/**
 * f_cmd - fork a an exec command to run cmd.
 *
 * @info:  parameter and return info struct.
 *
 * Return: void
 */
void f_cmd(info_tt *info)
{
	pid_t newpid;

	newpid = fork();
	if (newpid == -1)
	{
		perror("Error:");
		return;
	}
	if (newpid == 0)
	{
		if (execve(info->path, info->argv, getenv_fun(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				error_1(info, "Permission denied\n");
		}
	}
}
