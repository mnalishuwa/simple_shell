#include "main.h"

/**
 * main - super simple shell, can run commands with full path
 * Description: can run commands with full path without any
 * arguments
 *
 * Return: void
 */
int main(int argc, char **argv, char **env)
{
	signal(SIGINT, ctrlc_handler);
	int i = 0, __attribute__((unused)) n_read, _wstatus;
	char *user_entry, *exepath, *nint_entry[1024] = {0};
	pid_t child_pid, wchild_pid;
	struct _argv_argcount *arg_struct;
	char **argvec;

	if (isatty(STDIN_FILENO))
	{
		while (i < 3)
		{
			print_prompt();
			user_entry = read_line();
			printf("user_entry = %s\n", user_entry);
			if (check_inbuilt(user_entry, env) == 0)
			{
				continue;
			}
			arg_struct = _strtoargs(user_entry, " ");
			argvec = arg_struct->_args;
			if (!argvec)
			{
				printf("Error, please check command\n");
				return (1);
			}

			exepath = search_path(argvec[0]);
			/* free(argvec[0]); */
			/* argvec[0] = NULL; */
			argvec[0] = realloc(argvec[0], sizeof(char) * (strlen(exepath) + 1));
			argvec[0] = exepath;
			printf("Exec Path = %s, argv[0] = %s\n", exepath, argvec[0]);

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: failed to start process\n");
				return (1);
			}

			if (child_pid == 0)
			{
				if (execve(argvec[0], argvec, NULL) == -1)
				{
					printf("Error, program execution failed\n");
				}
			}
			else
			{
				wchild_pid = wait(&_wstatus);
				printf("Done waiting, child PID = %u\n", wchild_pid);
			}
			i++;

		}
	}
	else
	{
		printf("non_intercative mode\n");
		n_read = read(STDIN_FILENO, nint_entry, 1024);
		printf("entry = %s\n", (char *)nint_entry);
		arg_struct = _strtoargs((char *)nint_entry, " ");
		argvec = arg_struct->_args;

		rm_linefeed(argvec[1]);
		exepath = search_path(argvec[0]);
		/* free(argvec[0]); */
		/* argvec[0] = NULL; */
		/* argvec[0] = realloc(argvec[0], sizeof(char) * (strlen(exepath) + 1)); */
		argvec[0] = malloc(sizeof(char) * (strlen(exepath) + 1));
		argvec[0] = exepath;
		printf("Exec Path = %s, argv[0] = %s\n", exepath, argvec[0]);
		if(execve(argvec[0], argvec, NULL) == -1)
		{
			printf("Error, execve failed\n");
		}
		_exit_hsh(EXIT_SUCCESS);
	}
	free(user_entry);
	/*free(argvec);*/

	return (0);
}

/**
 * print_prompt - prints a prompt
 * Description: print a prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	printf("($) ");
}

/**
 * read_line - read a line of text
 * Description: reads a line of text from stdout
 * using getline function. it is the responsibility of
 * the caller to free the memory allocated.
 *
 * Return: a pointer to the string entered by the user
 */

char *read_line(void)
{
	char *_lineptr = NULL;
	const char __attribute__((unused)) *_OMODE = "r";
	ssize_t n_read;
	size_t len = 0;
	/* FILE *_std_input; */

	/* _std_input = fdopen(STDIN_FILENO, _OMODE); */

	n_read = getline(&_lineptr, &len, stdin);
	printf("nread = %zd, errno = %d, ENOMEN = %d, EINVAL=%d\n", n_read, errno, ENOMEM, EINVAL);
	eof_handler(n_read, errno);

	if (n_read == -1 && (errno == ENOMEM || errno == EINVAL))
	{
		perror("Error: ");
		return (NULL);
	}
	if (_lineptr[n_read - 1] == '\n')
		_lineptr[n_read - 1] = '\0';

	return (_lineptr);
}

/**
 * ctrlc_handler - handles SIGINT
 * Description: ensures program does not quit
 * on SIGINT signal
 *
 * @sig_int: int, signal num
 *
 * Return: void
 */
void ctrlc_handler(int sig_int)
{
	printf("Ctrl-c typed\n");
	print_prompt();
}

/**
 * eof_handler - receive CTRL-D perform graceful exit
 * Description: Use errno and getline return to check for CTRL-D,
 * when Ctrl-D is pressed. Exit gracefully.
 *
 * @nread: int, getline return value
 * @errno: int, errno value
 *
 * Return:  void
 */
void eof_handler(int nread, int e_no)
{
	/* if get line fails when Ctrl-D is typed */
	if (nread < 1 && (e_no != ENOMEM || e_no != EINVAL))
	{
		printf("Ctlr-D Handled, exiting gracefully ...\n");
		_exit_hsh(EXIT_SUCCESS);
	}
}

/**
 * _exit_hsh - call exit and exit program
 * Description: use exit syscall to terminate
 * process as necessary.
 *
 * @status: int, exit status
 *
 * Return: void
 */
void _exit_hsh(int status)
{
	printf("Now exiting\n");
	exit(status);
}

/**
 * _strip - removes any whitespace chars from a string
 * Description: takes a null terminated string and removes any
 * whitespace characters, it returns a string sans whitespace
 * it is the responsibility of the caller to free the memory after
 * use.
 *
 * @_str: string input
 *
 * Return: string or NULL
 */
char *_strip(char *_str)
{
	char *cln_str;
	size_t len_s, i, j;

	if (_str == NULL)
		return (NULL);

	len_s = strlen(_str);
	if (len_s == 0)
	{
		cln_str = malloc(sizeof(char));
		cln_str = "";
		free(_str);
		return (cln_str);
	}

	cln_str = malloc((len_s + 1) * sizeof(char));
	if (cln_str == NULL)
	{
		printf("Error, memory allocation failed\n");
		return (NULL);
	}

	for (i = 0, j = 0; _str[i] != '\0'; i++)
	{
		if (!_is_wspace(_str[i]))
		{
			cln_str[j] = _str[i];
			j++;
		}

	}
	cln_str[j] = _str[i];

	free(_str);
	return (cln_str);
}

/**
 * _is_wspace - checks if a character is a whitespace character
 * Description: receives a char and checks if is is a whitespace
 * character, line feed, vertical tab, tab, carriage return,
 * non breaking whitespace, line break are the characters checked
 *
 * @c: character argument
 *
 * Return: 1 if whitespace, 0 otherwise
 */
int _is_wspace(char c)
{
	size_t i = 0;

	while (_ASC_SPACES[i] != '\0')
	{
		if (c - _ASC_SPACES[i] == 0)
			return (1);
		i++;
	}
	return (0);
}
