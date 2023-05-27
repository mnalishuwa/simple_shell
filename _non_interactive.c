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
	char *lineptr = NULL, **args, *command, **rlines = NULL;
	int nrd = 0, i = 0, status = 0;
	char *rbuf = malloc(sizeof(char) * BLK_SIZE);

	_memset(rbuf, '\0', BLK_SIZE);
	while ((nrd = read(STDIN_FILENO, rbuf, BLK_SIZE)) > 0)
	{
		rlines = _strtok(rbuf, "\n");
		while (rlines[i] != NULL)
		{
			lineptr = _strdup(rlines[i]);
			normalize_wspace2(lineptr);
			args = _strtok(lineptr, " ");
			if (check_inbuilt(args[0], args, env) == 0)
			{
				i++;
				continue;
			}
			command = search_path(args[0], env);
			if (command == NULL)
			{
				cmd_not_found(args[0], args, status, env);
				i++;
				continue;
			}
			if (_strcmp(command, args[0]) == 0)
			{
				status = launch_program(args, env);
				free_args(args);
				i++;
				continue;
			}
			args[0] = _realloc(args[0], 0, sizeof(char) * (_strlen(command) + 1));
			_strncpy(args[0], command, _strlen(command) + 1);
			free(command);
			command = NULL;
			status = launch_program(args, env);
			free_args(args);
			i++;
		}
		free_args(rlines);
		rbuf = malloc(sizeof(char) * BLK_SIZE);
	}
	free(rbuf);
}
