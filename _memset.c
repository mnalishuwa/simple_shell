#include "main.h"

/**
 * _memset - fills memory with constant byte
 * Description: fills first n bytes of s with constant byte b
 *
 * @s: pointer to memory space to be filled with b
 * @b: contant byte
 * @n: number of bytes to be filled with b
 *
 * Return: the pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}

	return (s);
}
