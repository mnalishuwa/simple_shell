#include "main.h"

/**
 * _run_shell - loops the shell continuos
 * Description: loops the shell actions i.e. print prompt,
 * readline, tokenize line, check_inbuilt, execute command
 *
 * @env: environment pointer
 *
 * Return: void
 *
 */
void _run_shell(char **env)
{
	char *lineptr, **args, __attribute__((unused))*normalized_line, *command;
	int __attribute__((unused)) status = 0, i = 0;

	signal(SIGINT, ctrlc_handler);
	while (1)
	{
		i++;
		if (isatty(STDIN_FILENO))
			print_prompt();
		lineptr = read_line();
		if (_strlen(lineptr) == 0 || lineptr[0] == '\0' || lineptr[0] == '\n')
		{
			free(lineptr);
			lineptr = NULL;
			continue;
		}
		normalize_wspace2(lineptr);
		if (_strlen(lineptr) == 0)
		{
			free(lineptr);
			lineptr = NULL;
			continue;
		}
		args = _strtok(lineptr, " "); /* free(normalized_line); */
		if (check_inbuilt(args[0], args, env) == 0)
		{
			/* free_args(args); */
			continue;
		}
		command = search_path(args[0], env);
		if (command == NULL)
		{/* free_args(args); */
			cmd_not_found(args[0], args, i, env);
			continue;
		}
		if (_strcmp(command, args[0]) == 0)
		{
			status = launch_program(args, env);
			free_args(args);
			continue;
		}
		args[0] = _realloc(args[0], 0, sizeof(char) * (_strlen(command) + 1));
		_strncpy(args[0], command, _strlen(command) + 1);
		free(command);
		command = NULL;
		status = launch_program(args, env);
		free_args(args);
	}
}

/**
 * launch_program - executes a program using execve
 * Description: executes a program using execve
 *
 * @args: array, with command and arguments
 * @env: environment pointer
 *
 * Return: int
 */
int launch_program(char **args, char **env)
{
	int status;
	pid_t child_pid, __attribute__((unused)) wchild_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error: launch_program failed to start process:");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("./hsh:");
		}
	}
	else
	{
		wchild_pid = wait(&status);
	}
	return (1);
}
