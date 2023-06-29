#include "shell_.h"
int if_cmd(info_tt *info, char *path);
char *d_char(char *paths, int f_point, int e_point);
char *f_path(info_tt *info, char *paths, char *cmd);

/**
 * if_cmd - determines if a file is an executable command or not.
 *
 * @info: the info struct.
 *
 * @path: path to the file
 *
 * Return: 1 or 0.
 */
int if_cmd(info_tt *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}


/**
 * d_char - duplicate character.
 *
 * @paths: the PATH string.
 *
 * @f_point: the first index.
 *
 * @e_point: the last index.
 *
 * Return: pointer to new buffer.
 *
 */
char *d_char(char *paths, int f_point, int e_point)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = f_point; i < e_point; i++)
		if (paths[i] != ':')
			buf[j++] = paths[i];
	buf[j] = 0;
	return (buf);
}




/**
 * f_path - find this cmd in the input string.
 *
 * @info: the info struct.
 *
 * @paths: the input string.
 *
 * @cmd: the cmd to find.
 *
 * Return: full path of cmd if found or NULL.
 *
 */

char *f_path(info_tt *info, char *paths, char *cmd)
{
	int j = 0, cc = 0;
	char *path;

	if (!paths)
		return (NULL);
	if ((strlen_func(cmd) > 2) && starts_with_func(cmd, "./"))
	{
		if (if_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!paths[j] || paths[j] == ':')
		{
			path = d_char(paths, cc, j);
			if (!*path)
				strcat_func(path, cmd);
			else
			{
				strcat_func(path, "/");
				strcat_func(path, cmd);
			}
			if (if_cmd(info, path))
				return (path);
			if (!paths[j])
				break;
			cc = j;
		}
		j++;
	}
	return (NULL);
}
