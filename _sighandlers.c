#include "main.h"

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
	(void)sig_int;
	signal(SIGINT, ctrlc_handler);
	/* _puts("Ctrl-c typed\n"); */
	_puts("\n");
	print_prompt();
}

/**
 * eof_handler - receive CTRL-D perform graceful exit
 * Description: Use errno and getline return to check for CTRL-D,
 * when Ctrl-D is pressed. Exit gracefully.
 *
 * @nread: int, getline return value
 * @e_no: int, errno value
 * @lineptr: string
 *
 * Return:  void
 */
void eof_handler(int nread, int e_no, char *lineptr)
{
	/* if get line fails when Ctrl-D is typed */
	if (nread < 1 && (e_no != ENOMEM || e_no != EINVAL))
	{
		/* _puts("Ctlr-D Handled, exiting gracefully ...\n"); */
		_exit_hsh(lineptr, NULL, EXIT_SUCCESS);
	}
}

/**
 * _exit_hsh - call exit and exit program
 * Description: use exit syscall to terminate
 * process as necessary.
 *
 * @status: int, exit status
 * @lineptr: string command
 * @args: arguments array
 *
 * Return: void
 */
void _exit_hsh(char *lineptr, char **args, int status)
{
	(void)lineptr;
	/* _puts("Now exiting\n"); */
	/* if (lineptr != NULL) */
	/*	free(lineptr); */
	if (args != NULL)
		free_args(args);
	exit(status);
}
