#include "main.h"

/**
 * _printenv - prints environment
 * Description: prints environment using global variable environ
 *
 * @env: environment array pointer
 *
 * Return: 0 Success
 */

void _printenv(char **env)
{
	size_t i = 0;

	while (env[i] != NULL)
	{
		puts(env[i]);
		i++;
	}

}
