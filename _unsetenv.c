#include "main.h"

/**
 * _unsetenv - removes a variable from the enviroment
 * Description: deletes the variable name from the enviroment
 * @name: Variable
 * Return: On success - 0, else -1 if failure
 */

int _unsetenv(const char *name)
{
	if (_unsetenv(name) != 0)
	{
		write(stderr, "Error unsetting enviroment variavle %s\n", name);
		return (-1);
	}

	return (0);
}
