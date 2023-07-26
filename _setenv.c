#include "main.h"

/**
 * _setenv_ls - sets an environment variable
 * Description: sets an environment variable
 *
 * @name: var name
 * @value: var value
 * @overwrite: overwrite indicator
 * @env: environment variable array
 *
 * Return: int
 */

int _setenv(char *name, char *value, int overwrite, enode *env)
{
	enode *current_node = env, __attribute__((unused))**env_addr = &env;

	if (name == NULL || value == NULL)
	{
		write(STDERR_FILENO, _SETENVERR, 25);
		return (-1);
	}

	while (current_node)
	{
		if (_strcmp(name, current_node->name) == 0)
		{
			if (overwrite == 0)
				return (0);
/* current_node->value = _realloc(current_node->value, 0, _strlen(value) + 1);*/
			free(current_node->value);
			current_node->value = NULL;
			current_node->value = _strdup(value);
			return (0);
		}
		current_node = current_node->next_node;
	}
	current_node = add_node_end(env, name, value);
/* case for when *env = NULL*/
/* check if refactor to receive &env instead of env is necessary*/
/* if (*env_addr == NULL) */
/* *env_addr = current_node; */
	if (current_node == NULL)
		return (-1);
	return (0);
}

/**
 * create_path - concatenates 2 strings into specified destination
 * Description: concats 2 strings separated by a / to specified
 * destination, this is used to create a full filepath given
 * a directory and a command, it is a utility function used
 * to help search_path to search through PATH files for a
 * command/program
 *
 * @dest: output string
 * @s1: foldername string
 * @s2: command/program name
 * @sep: separator
 *
 * Return: void
 */
void create_path2(char *dest, char *s1, char *s2, char sep)
{
	size_t i, j;

	if (dest == NULL || s1 == NULL || s2 == NULL)
	{
		perror("error: create_path passed null\n");
	}

	for (i = 0; s1[i] != '\0'; i++)
		dest[i] = s1[i];
	dest[i] = sep;
	i++;
	for (j = 0; s2[j] != '\0'; j++)
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
}

/**
 * copy_args - copys a string array
 * Description: copies an array of strings
 *
 * @args: string array
 *
 * Return: pointer to copied array or NULL otherwise
 */
char **copy_args(char **args)
{
	size_t i, len_args;
	char **args_copy;

	if (args == NULL)
		return (NULL);

	for (len_args = 0; args[len_args] != NULL; len_args++)
		;
	args_copy = malloc(sizeof(char *) * len_args);

	for (i = 0; i < len_args; i++)
	{
		args_copy[i] = _strdup(args[i]);
	}

	return (args_copy);
}
