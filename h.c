#include "shell_.h"

char *find_history_file(info_tt *info);
int history_w(info_tt *info);



/**
 * find_history_file - find the history file.
 *
 * @info: parameter struct.
 *
 * Return: allocated string containg history file.
 */

char *find_history_file(info_tt *info)
{
	char *buf, *dr;

	dr = getenv_fun(info, "HOME=");
	if (!dr)
		return (NULL);
	buf = malloc(sizeof(char) * (strlen_func(dr) + strlen_func(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	strcpy_func1(buf, dr);
	strcat_func(buf, "/");
	strcat_func(buf, HIST_FILE);
	return (buf);
}




/**
 * history_w - creates a file, or add to an existing file.
 * @info: the parameter struct.
 *
 * Return: 1 or -1.
 */


int history_w(info_tt *info)
{
	ssize_t f_d;
	char *fname = find_history_file(info);
	my_list_t *node = NULL;

	if (!fname)
		return (-1);

	f_d = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (f_d == -1)
		return (-1);
	for (node = info->the_history; node; node = node->next)
	{
		putsfd_d(node->s, f_d);
		putfd_func('\n', f_d);
	}
	putfd_func(BUF_FLUSH, f_d);
	close(f_d);
	return (1);
}

/**
 * history_rm - renumber the history list after change.
 *
 * @info: Structure containing potential arguments.
 *
 * Return:  histcount.
 */
int history_rm(info_tt *info)
{
	my_list_t *node = info->the_history;
	int j = 0;

	while (node)
	{
		node->number = j++;
		node = node->next;
	}
	return (info->historycount = j);
}

/**
 * bhistoryl - add entry to a history list.
 *
 * @info: Structure containing potential arguments.
 * @buf:the buffer.
 *
 * @l_count:history  number of line count .
 *
 * Return: 0.
 */
int bhistoryl(info_tt *info, char *buf, int l_count)
{
	my_list_t *node = NULL;

	if (info->the_history)
		node = info->the_history;
	insert_node(&node, buf, l_count);

	if (!info->the_history)
		info->the_history = node;
	return (0);
}

/**
 * history_r - read history from file.
 *
 * @info: the parameter struct.
 *
 * Return: histcount on success, or 0.
 */
int history_r(info_tt *info)
{
	int j, end = 0, l_count = 0;
	ssize_t f_d, rlen, sizee = 0;
	struct stat st;
	char *buf = NULL, *fname = find_history_file(info);

	if (!fname)
		return (0);

	f_d = open(fname, O_RDONLY);
	free(fname);
	if (f_d == -1)
		return (0);
	if (!fstat(f_d, &st))
		sizee = st.st_size;
	if (sizee < 2)
		return (0);
	buf = malloc(sizeof(char) * (sizee + 1));
	if (!buf)
		return (0);
	rlen = read(f_d, buf, sizee);
	buf[sizee] = 0;
	if (rlen <= 0)
		return (free(buf), 0);
	close(f_d);
	for (j = 0; j < sizee; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			bhistoryl(info, buf + end, l_count++);
			end = j + 1;
		}
	if (end != j)
		bhistoryl(info, buf + end, l_count++);
	free(buf);
	info->historycount = l_count;
	while (info->historycount-- >= HIST_MAX)
		delete_index(&(info->the_history), 0);
	history_rm(info);
	return (info->historycount);
}
