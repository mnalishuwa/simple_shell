#include "main.h"

/**
 * check_inbuilt - check if command is inbuilt
 * Description: takes a str command and compares it
 * in order to call the correct inbuilt command
 *
 * @command: str, user command
 * @env: environment pointer
 * @args: arguments array
 *
 * Return: value
 */
int check_inbuilt(char *command, char **args, char **env)
{
	size_t i;

	char *builtins[] = {"env", "exit", "setenv", "cd", NULL};

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(builtins[i], command) == 0)
		{
			if (i == 0)
			{
				_printenv(env);
				return (0);
			}
			if (i == 1)
			{
				if (args[1])
					_exit_hsh(command, args, _atoi(args[1]));
				_exit_hsh(command, args, EXIT_SUCCESS);
				return (0);
			}
		}
	}
	return (1);
}
