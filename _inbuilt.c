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
int check_inbuilt(char *command, char **args, enode *env)
{
	size_t i;
	char *builtins[] = {"env", "exit", "setenv", "cd", "unsetenv", NULL};

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(builtins[i], command) == 0)
		{
			return (_run_inbuilt(command, args, i, env));
		}
	}
	return (1);
}

/**
 * _len_args - gets the number of arguments
 * Description: receives an array of string and returns the number of arguments
 *
 * @args: string array
 *
 * Return: int, number of arguments
 */
int _len_args(char **args)
{
	size_t arglen;


	if (args == NULL)
		return (-1);

	for (arglen = 0; args[arglen] != NULL; arglen++)
		;

	return (arglen);
}

/**
 * _run_inbuilt - helper function for check inbuilt
 * Description: runs inbuilt functions, reduces lines in check inbuilt
 *
 * @args: arguments array
 * @i: function number
 * @env: env variable linked list
 * @command: str command
 *
 * Return: int
 */
int _run_inbuilt(char *command, char **args, int i, enode *env)
{
	char *ENV_HOME;

	if (i == 0)
	{
		_printenv(env);
		free_args(args);
		return (0);
	}
	if (i == 1)
	{
		if (args[1])
			_exit_hsh(command, args, env, _atoi(args[1]));
		_exit_hsh(command, args, env, EXIT_SUCCESS);
		return (0);
	}
	if (i == 2)
	{
		if (_len_args(args) != 3)
			_setenv(NULL, NULL, 0, env);
		else
			_setenv(args[1], args[2], 1, env);
		free_args(args);
		return (0);
	}
	if (i == 3)
	{
		ENV_HOME = _getenv("HOME", env);
		(_len_args(args) == 1) ? _cdir(ENV_HOME, env) : _cdir(args[1], env);
		free_null(ENV_HOME);
		free_args(args);
		return (0);
	}
	if (i == 4)
	{
		(_len_args(args) != 2) ? _unsetenv(NULL, &env) : _unsetenv(args[1], &env);
		free_args(args);
		return (0);
	}
	return (0);
}
