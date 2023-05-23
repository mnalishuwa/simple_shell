#include "main.h"

/**
 * main - runs getenv
 * Description: test implementation of getenv function
 *
 * Return: 0 success
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv, char **env)
{
	char *_path = getenv("PATH");
	char *env_var_val = _getenv("PATH", env);
	printf("%s\n%s\n", env_var_val, _path);
}

/**
 * _getenv - get the value of an environment variable
 * Description: takes a string argument and checks if the
 * argument passed exists as a variable in the environment
 * it returns the value if it exists or null otherwise.
 *
 * @name: str, variable name
 *
 * Return: str, variable value, or null otherwise
 */
char *_getenv(const char *name, char **env)
{
	size_t i, j, vval_len;
	char *var_name = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		var_name = realloc(var_name, sizeof(char) * strlen(env[i]));
		for (j = 0; env[i][j] != '='; j++)
		{
			var_name[j] = env[i][j];
		}
		var_name[j] = '\0';
		j++;

		if (strcmp(name, var_name) == 0)
		{
			for (vval_len = 0; env[i][j] != '\0'; vval_len++, j++)
			{
				var_name[vval_len] = env[i][j];
			}
			var_name[vval_len] = env[i][j];
			return (var_name);
		}
	}
	free(var_name);
	return (NULL);
}
