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

	_run_shell(env);

	return (0);
}
