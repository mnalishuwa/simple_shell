#include "main.h"

/* int main(void) */
/* { */
/* 	char s[] = "less"; */
/* 	char *test_args; */
/* 	/\* struct _arg_argcount test_args; *\/ */

/* 	test_args = search_path(s); */
/* 	printf("search p = %s\n", test_args); */
/* } */

/**
 * search_path - function searchs for a command on the path
 * Description: searches the path for a command and returns
 * the full path if found, or null otherwise
 *
 * @command: str, command entry
 *
 * Return: command path to executable, or NULL if not found
 */

char *search_path(char *command)
{
	size_t _dir_size = 0, cmd_size = 0;
	char *_path, *cln_command, *_dir_token, *_stat_path = NULL;
	const char *ENV_VAR = "PATH";
	struct _argv_argcount *_argvc;
	struct stat stat_buf;

	_path = getenv(ENV_VAR);
	if (!_path)
	{
		printf("Error: %s not in environment", ENV_VAR);
		return (NULL);
	}

	if (!command || strlen(command) == 0)
	{
		return (NULL);
	}

	printf("command = %s\n", command);
	if (command[0] == '/')
	{
		if (stat(command, &stat_buf) == 0)
			return (command);
		return (NULL);
	}

	_argvc = _strtoargs(command, "/");
	cln_command = _argvc->_args[_argvc->_count - 1];
	printf("cln_command = %s\n", cln_command);
	rm_linefeed(cln_command);
	printf("PATH=%s\n", _path);
	_dir_token = strtok(strdup(_path), ":");
	while (_dir_token != NULL)
	{
		_dir_size = strlen(_dir_token);
		_stat_path = realloc(_stat_path, sizeof(char) * (_dir_size + cmd_size + 2));
		sprintf(_stat_path, "%s/%s", _dir_token, cln_command);
		printf("path = %s, dir = %s/%s\n", _stat_path, _dir_token, cln_command);
		if (stat(_stat_path, &stat_buf) == 0)
		{
			return (_stat_path);
		}
		_dir_token = strtok(NULL, ":");
	}

	return (NULL);
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


/**
 * cmdline_to_argv - splits a string into individual arguments
 * Desciption: takes a string and returns an array of the individual
 * word strings. It is the responsibility of the caller to memory allocated.
 *
 * @_str: input string
 * @_DELIM: char, character to delimit on
 *
 * Return: Array of strings
 */
struct _argv_argcount *_strtoargs(char *_str, const char __attribute__((unused)) *_DELIM)
{
	char **_argv = NULL, *_tokn;
	const char *DELIMITER;
	size_t wcount = 0, _av_bytes = 0; /*tkn_size = 0;*/
	struct _argv_argcount *_argv_wcount;

	_argv_wcount = malloc(sizeof (struct _argv_argcount));

	if (_str == NULL || strlen(_str) == 0)
	{
		printf("Error occured, Invalid Input2.\n");
		return (NULL);
	}

	if (_DELIM)
		DELIMITER = _DELIM;
	else
		DELIMITER = " ";

	_tokn = strtok(_str, DELIMITER);
	while (_tokn != NULL)
	{
		_av_bytes = (sizeof(char *) * (wcount + 1));
		_argv = realloc(_argv, _av_bytes);
		if (!_argv)
		{
			free(_argv);
			return (NULL);
		}

		_argv[wcount] = _tokn;
		wcount++;
		_tokn = strtok(NULL, DELIMITER);
	}
	_argv = realloc(_argv, sizeof(char *) * (wcount + 1));
	_argv[wcount] = NULL;
	_argv_wcount->_args = _argv;
	_argv_wcount->_count = wcount;
	return (_argv_wcount);
}
