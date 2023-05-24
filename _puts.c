#include "main.h"

/**
 * _puts - prints a string to stdout
 * Description: takes a string argument *str and outputs the string to stdout
 *
 * @str: string input
 *
 * Return: void
 */

void _puts(char *str)
{
	int char_index;

	for (char_index = 0; *(str + char_index) != '\0'; char_index++)
		_putchar(*(str + char_index));
}
