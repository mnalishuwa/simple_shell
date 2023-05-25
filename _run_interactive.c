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
	char *lineptr, **args, *normalized_line, *command;
	int status = 0, i = 1;

	while (i)
	{
		signal(SIGINT, ctrlc_handler);
		print_prompt();
		lineptr = read_line();
		normalized_line = normalize_wspace(lineptr, _strlen(lineptr));
		args = _strtok(normalized_line, " "); /* free(normalized_line); */
		if (check_inbuilt(args[0], env) == 0)
			continue;
		command = search_path(args[0], env);
		if (command == NULL)
		{
			cmd_not_found(args[0], status, env);
		}
		/* free(args[0]); */
		args[0] = malloc(sizeof(char) * (_strlen(command) + 1));
		_strncpy(args[0], command, _strlen(command) + 1);
		/* free(command); */
		status = launch_program(args, env);
		/* free(lineptr); */
		/* free_args(args); */
		/* i++; */
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
