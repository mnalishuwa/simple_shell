#include "main.h"

/**
 * _non_interactive - executes shell in non-interactive mode
 * Description: executes shell with input from pipe or redirection
 *
 * @env: environment pointer
 *
 * Return: void
*/
void _non_interactive(char **env)
{
	char *lineptr, **args, *command;
	int status = 0;

	lineptr = read_line();
	normalize_wspace2(lineptr);
	args = _strtok(lineptr, " ");
	if (check_inbuilt(args[0], args, env) == 0)
		_exit_hsh(args[0], args, EXIT_SUCCESS);
	command = search_path(args[0], env);
	if (command == NULL)
	{
		cmd_not_found(args[0], args, status, env);
		_exit_hsh(command, args, EXIT_SUCCESS);
	}
	if (_strcmp(command, args[0]) == 0)
	{
		status = launch_program(args, env);
		_exit_hsh(command, args, EXIT_SUCCESS);
	}
	args[0] = _realloc(args[0], 0, sizeof(char) * (_strlen(command) + 1));
	_strncpy(args[0], command, _strlen(command) + 1);
	free(command);
	command = NULL;
	status = launch_program(args, env);
	_exit_hsh(command, args, EXIT_SUCCESS);
}
