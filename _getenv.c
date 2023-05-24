#include "main.h"

/**
 * _getenv - get the value of an environment variable
 * Description: takes a string argument and checks if the
 * argument passed exists as a variable in the environment
 * it returns the value if it exists or null otherwise.
 * _getenv returns a dynamically allocated string, it is
 * the responsibility of the caller to free the memory
 * after use.
 *
 * @name: str, variable name
 * @env: environment pointer
 *
 * Return: str, variable value, or null otherwise
 */
char *_getenv(const char *name, char **env)
{
	size_t i, j, var_value_len;
	char *var_name = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		var_name = _realloc(var_name, 0, sizeof(char) * _strlen(env[i]));
		for (j = 0; env[i][j] != '='; j++)
		{
			var_name[j] = env[i][j];
		}
		var_name[j] = '\0';
		j++;

		if (_strcmp((char *)name, var_name) == 0)
		{
			for (var_value_len = 0; env[i][j] != '\0'; var_value_len++, j++)
			{
				var_name[var_value_len] = env[i][j];
			}
			var_name[var_value_len] = env[i][j];
			return (var_name);
		}
	}
	free(var_name);
	return (NULL);
}
