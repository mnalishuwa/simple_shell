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
 * @vname: str, variable name
 * @env: environment pointer
 *
 * Return: str, variable value, or null otherwise
 */
char *_getenv(const char *vname, enode *env)
{
	char *vvalue = NULL;
	enode *current_node = env;

	if (vname == NULL || env == NULL)
		return (NULL);

	while (current_node)
	{
		if (_strcmp((char *)vname, current_node->name) == 0)
		{
			vvalue = _strdup(current_node->value);
			return (vvalue);
		}
		current_node = current_node->next_node;
	}
	return (NULL);
}
