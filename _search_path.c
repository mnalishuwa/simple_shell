#include "main.h"

/**
 * search_path - function searchs for a command on the path
 * Description: searches the path for a command and returns
 * the full path if found, or null otherwise. It used
 * dynamic memory allocation, it is the responsibility of
 * the caller to free the memory after use.
 *
 * @command: str, command entry
 * @env: environment pointer
 *
 * Return: command path to executable, or NULL if not found
 */
char *search_path(char *command, char **env)
{
	size_t dir_len = 0, clen = 0, i;
	char *pathvalue, **pathdirs, *full_cpath = NULL;
	const char *PATH_VARNAME = "PATH";
	struct stat stat_buf;

	pathvalue = _getenv(PATH_VARNAME, env);
	if (pathvalue == NULL || command == NULL || _strlen(command) == 0)
	{
		free(pathvalue);
		pathvalue = NULL;
		return (NULL);
	}
	clen = _strlen(command);
	if (is_pathbased(command) == 1)
	{
		if (stat(command, &stat_buf) == 0)
		{
			free(pathvalue);
			pathvalue = NULL;
			return (command);
		}
		return (NULL);
	}
	pathdirs = _strtok(pathvalue, ":");
	/* free(pathvalue); */
	/* pathvalue = NULL; */
	for (i = 0; pathdirs[i] != NULL; i++)
	{
		dir_len = _strlen(pathdirs[i]);
		full_cpath = _realloc(full_cpath, 0, sizeof(char) * (dir_len + clen + 2));
		create_path(full_cpath, pathdirs[i], command);/* printf("fpath\n"); */
		if (stat(full_cpath, &stat_buf) == 0)
		{/* printf("Command found = %s\n", full_cpath); */
			free_args(pathdirs);
			return (full_cpath);
		}
	}
	free(full_cpath);
	free_args(pathdirs);
	return (NULL);
}

/**
 * free_args - frees a dynamically allocated array of strings
 * Description: frees an array of strings
 *
 * @args: string array to be freed
 *
 * Return: void
*/
void free_args(char **args)
{
	size_t i;

	if (args == NULL)
	{
		perror("error - free_args, args is null");
		return;
	}

	for (i = 0; args[i] != NULL; i++)
	{
		if (args != NULL)
			free(args[i]);
		args[i] = NULL;
	}
	free(args);
	args = NULL;
}

/**
 * create_path - concatenates 2 strings into specified destination
 * Description concats 2 strings separated by a / to specified
 * destination, this is used to create a full filepath given
 * a directory and a command, it is a utility function used
 * to help search_path to search through PATH files for a
 * command/program
 *
 * @dest: output string
 * @s1: foldername string
 * @s2: command/program name
 *
 * Return: void
*/
void create_path(char *dest, char *s1, char *s2)
{
	size_t i, j;

	if (dest == NULL || s1 == NULL || s2 == NULL)
	{
		perror("error: create_path passed null\n");
	}

	for (i = 0; s1[i] != '\0'; i++)
		dest[i] = s1[i];
	dest[i] = '/';
	i++;
	for (j = 0; s2[j] != '\0'; j++)
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
}

/**
 * is_pathbased - checks if command contains forward slash
 * Description: checks if forward slash is in the command,
 * if / is in the command, it indicates the command should
 * be path based and the search for the program should occur
 * on the path specified.
 *
 * @command: string command
 *
 * Return: 1 if path is specified in the command, 0 otherwise,
 * -1 for an error
*/
int is_pathbased(char *command)
{
	size_t i;

	if (command == NULL)
	{
		perror("error: is_abs_relative passed null\n");
		return (-1);
	}

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (1);
	}

	return (0);
}

/**
 * rm_linefeed - removes newline character at the end of a line
 * Description: removes a newline character from the string at the end
 *
 * @_str: string argument
 *
 * Return: void
 */
void rm_linefeed(char *_str)
{
	size_t len_s;

	if (_str == NULL)
	{
		puts("error: passed NULL to remove linefeed function\n");
		return;
	}

	len_s = strlen(_str);
	if (_str[len_s - 1] == '\n')
		_str[len_s - 1] = '\0';
}
