#include "shell_.h"
#include <stdlib.h>
#include <unistd.h>

char **getenviron_fun(info_tt *info);
int __unsetenv(info_tt *info, char *v);
int __setenv(info_tt *info, char *v, char *u);





/**
 * getenviron_fun - returns string arr copy of our environ
 *
 * @v: var
 *
 * Return: 0
*/

char **getenviron_fun(const char *v)
{
	int dex, l;

	l = strlen_func(v);
	for (dex = 0; environ[dex]; dex++)
	{
		if (strcmp_func(v, environ[dex], l) == 0)
			return (&environ[dex]);
	}

	return (NULL);
}

/**
 * __unsetenv - remove env variable
 *
 * @ar: struct
 * @fr: string env var
 *
 * Return: 1 if delete else 0
*/

int __unsetenv(char **ar, char **fr)
{
	char **env_v, **new_env;
	size_t sz;
	int dex, dex2;

	if (!ar[0])
		return (create_error(ar, -1));
	env_v = getenviron_fun(arg[0]);
	if (!env_v)
		return (0);

	for (sz = 0; environ[sz]; sz++)
		;

	new_env = malloc(sizeof(char *) * sz);
	if (!new_env)
		return (create_error(ar, -1));

	for (dex = 0, dex2 = 0; environ[dex]; dex++)
	{
		if (*env_v == environ[dex])
		{
			free(*env_v);
			continue;
		}
		new_env[dex2] = env[dex];
		dex2++;
	}
	free(environ);
	environ = new_env;
	env[sz - 1] = NULL;

	return (0);
}

/**
 * __setenv - initialize new env var
 *
 * @ar: string env var
 * @fr: env var value
 *
 * Return: 0
*/

int __setenv(char **ar, char **fr)
{
	char **env_v = NULL, **new_env, *new_lue;
	size_t sz;
	int dex;

	if (!ar[0] || !ar[1])
		return (create_error(ar, -1));

	new_lue = malloc(strlen_func(ar[0]) + 1 + strlen_func(ar[1]) + 1);
	if (!new_lue)
		return (create_error(ar, -1));
	strcpy_func1(new_lue, ar[0]);
	strcat_func(new_lue, "=");
	strcat_func(new_lue, ar[1]);

	env_v = getenviron_fun(ar[0]);
	if (env_v)
	{
		free(*env_v);
		*env_v = new_lue;
		return (0);
	}
	for (sz = 0; environ[sz]; sz++)
		;

	new_env = malloc(sizeof(char *) * (sz + 2));
	if (!new_env)
	{
		free(new_lue);
		return (create_error(ar, -1));
	}

	for (dex = 0; environ[dex]; dex++)
		new_env[dex] = environ[dex];

	free(environ);
	environ = new_env;
	environ[dex] = new_lue;
	environ[dex + 1] = NULL;

	return (0);
}
