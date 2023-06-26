#include "shell_.h"

/**
 * main - entry point
 *
 * @ao: arg count
 * @a: arg vector
 *
 * Return: 0 success else 1
*/

int main(int ao, char **a)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ao == 2)
	{
		fd = open(a[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(a[0]);
				_eputs(": 0: Can't open ");
				_eputs(a[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	penv_list(info);
	history_r(info);
	mshell(info, a);
	return (EXIT_SUCCESS);
}
