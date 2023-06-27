#include "shell_.h"

/**
 * mshell - main shell loop
 *
 * @info: struct
 * @ar: argument
 *
 * Return: 0 success else 1
*/

<<<<<<< HEAD
int mshell(info_tt *info, char **a)
=======
int mshell(info_tt *info, char **ar)
>>>>>>> 8eaf88e474df28ccb929a9920a9e2e65e1868298
{
	ssize_t n = 0;
	int br = 0;

	while (n != -1 && br != -2)
	{
		clearinfo_fun(info);
		if (interactive_fun(info))
<<<<<<< HEAD
			_puts("$ ");
=======
			puts_func("$ ");
>>>>>>> 8eaf88e474df28ccb929a9920a9e2e65e1868298
		eputchar_func(BUF_FLUSH);
		n = getinput_fun(info);
		if (n != -1)
		{
			setinfo_fun(info, ar);
			br = findbuilt_fun(info);
			if (br == -1)
				git_cmd(info);
		}
		else if (interactive_fun(info))
			_putcharr('\n');
		freeinfo_fun(info, 0);
	}
	history_w(info);
	freeinfo_fun(info, 1);

	if (!interactive_fun(info) && info->statuss)
		exit_fun(info->statuss);

	if (br == -2)
	{
		if (info->err_num == -1)
			exit_fun(info->statuss);
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
	builtintable builtin[] = {
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

	for (n = 0; builtin[n].type; n++)
		if (strcmp_func(info->arg_v[0], builtin[n].type) == 0)
		{
			info->l_count++;
			br = builtin[n].fun(info);
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

void git_cmd(info_tt *info)
{
	char *input = NULL;
	int i, j;

	info->input = info->arg_v[0];
	if (info->lcount_ch == 1)
	{
		info->l_count++;
		info->lcount_ch = 0;
	}
	for (i = 0, j = 0; info->arg[i]; i++)
<<<<<<< HEAD
		if (!isdelim_func(info->arg[i], " \t\n"))
=======
		if (!isdelim_fun(info->arg[i], " \t\n"))
>>>>>>> 8eaf88e474df28ccb929a9920a9e2e65e1868298
			j++;
	if (!j)
		return;

	input = f_path(info, getenv_fun(info, "PATH="), info->arg_v[0]);
	if (input)
	{
		info->input = input;
		f_cmd(info);
	}
	else
	{
		if ((interactive_fun(info) || getenv_fun(info, "PATH=")
			|| info->arg_v[0][0] == '/') && if_cmd(info, info->arg_v[0]))
			f_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->statuss = 127;
			put_error(info, "not found\n");
		}
	}
}


/**
 * f_cmd - fork a an exec command to run cmd.
 *
 * @info:  parameter and return info struct.
 *
 * Return: void
<<<<<<< HEAD
 */
=======
*/

>>>>>>> 8eaf88e474df28ccb929a9920a9e2e65e1868298
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
		if (execve(info->input, info->arg_v, getenviron_fun(info)) == -1)
		{
			freeinfo_fun(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->statuss));
		if (WIFEXITED(info->statuss))
		{
			info->statuss = WEXITSTATUS(info->statuss);
			if (info->statuss == 126)
				put_error(info, "Permission denied\n");
		}
	}
}
