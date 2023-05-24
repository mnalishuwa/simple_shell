#include "main.h"

/**
 * cmd_not_found - displays error message similar to sh
 * Description: creates a custom error message when
 * command not found
 *
 * @command: str / command entry
 * @num: int, command number
 * @env: pointer to environment array
 *
 * Return: void
 */
void cmd_not_found(char *command, int num, char **env)
{
	char *exe_name;

	exe_name = _getenv("_", env);

	_puts(exe_name);
	_puts(": ");
	print_number(num);
	_puts(": ");
	_puts(command);
	_puts(": ");
	_puts("not found\n");
}