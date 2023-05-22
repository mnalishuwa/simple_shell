#include "main.h"

extern char **environ;

int main(void)
{
	int res = _setenv("PATH", "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", 1);
	printf("res = %d", res);
	return (0);
}
/**
 * _setenv - sets an environment variable
 * Description: changes the value of an environment variable if it exists,
 * add a new one if it doesn't exist.
 *
 * @name: str, variable name
 * @value: str, value
 * @overwrite: int, indicating overwrite if variable exists in the environment
 *
 * Return: int, 0 on success, -1 otherwise
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t i, _total_size;
	char *var_name, *var_cpy;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	if (overwrite == 0)
	{
		return (0);
	}

	_total_size = strlen(name) + strlen(value) + 2;
	printf("size = %lu\n", _total_size);
	for (i = 0; environ[i] != NULL; i++)
	{
		var_cpy = strdup(environ[i]);
		if (!var_cpy)
		{
			printf("Error: string duplication failed\n");
			return (-1);
		}
		var_name = strtok(var_cpy, "=");
		printf("%s\n%s\n", environ[i], var_name);
		if (strcmp(name, var_name) == 0)
		{
			environ[i] = realloc(environ[i], sizeof(char) * _total_size);
			if (!environ[i])
			{
				printf("Error: memory allocation failed\n");
				return (-1);
			}
			sprintf(environ[i], "%s=%s", name, value);
			return (0);
		}
	}
	environ = realloc(environ, sizeof(char *) * (i + 1));
	environ[i] = realloc(environ[i], sizeof(char) * _total_size);
	if (!environ || !environ[i])
	{
		printf("Error: memory allocation failed\n");
		return (-1);
	}
	sprintf(environ[i], "%s=%s", name, value);
	environ[i + 1] == NULL;
	free(var_cpy);

	return (0);
}
