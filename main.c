#include "main.h"

/**
 * main - start hsh
 * Description: run custom shell program
 *
 * @argc: int, argument count
 * @argv: argument array
 * @env: environment pointer
 *
 * Return: int
*/
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
	{
		_run_shell(env);
	}
	else
	{
		_non_interactive(env);
	}

	return (0);
}
