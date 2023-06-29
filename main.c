#include "shell.h"

/**
 * main - entry point
 *
 * @ao: arg count
 * @ar: arg vector
 *
 * Return: 0 success else 1
*/

int main(int ao, char **ar)
{
	info_tt info[] = { INFO__INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (f)
			: "r" (f));

	if (ao == 2)
	{
		f = open(ar[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eputs_func(ar[0]);
				eputs_func(": 0: Can't open ");
				eputs_func(ar[1]);
				eputchar_func('\n');
				eputchar_func(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readf = f;
	}
	popenv_list(info);
	history_r(info);
	hsh(info, ar);
	return (EXIT_SUCCESS);
}
