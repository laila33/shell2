#include "shell_.h"

/**
 * if_cmd - determines if a file is an executable command or not.
 *
 * @info: the info struct.
 *
 * @input: path to the file
 *
 * Return: 1 or 0.
 */
int if_cmd(info_tt *info, char *input)
{
	struct stat st;

	(void)info;
	if (!input || stat(input, &st))
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
 * @inputs: the PATH string.
 *
 * @f_point: the first index.
 *
 * @e_point: the last index.
 *
 * Return: pointer to new buffer.
 *
 */
char *d_char(char *inputs, int f_point, int e_point)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = f_point; i < e_point; i++)
		if (inputs[i] != ':')
			buf[j++] = inputs[i];
	buf[j] = 0;
	return (buf);
}




/**
 * f_path - find this cmd in the input string.
 *
 * @info: the info struct.
 *
 * @inputs: the input string.
 *
 * @cmd: the cmd to find.
 *
 * Return: full path of cmd if found or NULL.
 *
 */

char *f_path(info_tt *info, char *inputs, char *cmd)
{
	int j = 0, cc = 0;
	char *input;

	if (!inputs)
		return (NULL);
	if ((strlen_func(cmd) > 2) && starts_with_func(cmd, "./"))
	{
		if (if_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!inputs[j] || inputs[j] == ':')
		{
			input = d_char(inputs, cc, j);
			if (!*input)
				strcat_func(input, cmd);
			else
			{
				strcat_func(input, "/");
				strcat_func(input, cmd);
			}
			if (if_cmd(info, input))
				return (input);
			if (!inputs[j])
				break;
			cc = j;
		}
		j++;
	}
	return (NULL);
}
