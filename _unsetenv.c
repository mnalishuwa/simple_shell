#include "main.h"

/**
 * _unsetenv - removes a variable from the environment
 * Description: takes a variable name and removes it from the environment
 * if it exists
 *
 * @name: string, variable name
 * @env: env variables linked list
 *
 * Return: int, 0 on success and -1 otherwise
 */
int _unsetenv(char *name, enode **env)
{
	int res;

	if (env == NULL)
		return (-1);

	res = delete_node(env, name);
	if (name == NULL || res == -1)
	{
		write(STDERR_FILENO, _UNSETENVERR, 21);
		return (-1);
	}

	return (res);
}
