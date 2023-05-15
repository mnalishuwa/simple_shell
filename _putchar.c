#include "main.h"

/**
 * _putchar - write byte to stdout
 * Description: write a single byte to stdout using write system call
 *
 * @c: char to be written to stdout
 *
 * Return: int, 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
