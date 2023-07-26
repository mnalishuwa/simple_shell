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
	enode *_env = NULL;

	(void)argc;
	(void)argv;

	_env = strargs_tolist(env);
	_run_shell(_env);

	return (0);
}
