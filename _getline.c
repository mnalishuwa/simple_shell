#include "main.h"

/* int main(void) */
/* { */
/* 	char *s = NULL; */
/* 	size_t len = 0; */
/* 	ssize_t nchars; */

/* 	nchars = _getline(&s, &len, stdin); */

/* 	printf("s = %s\nlen = %zu\nnchars = %zd\nlen s = %zu\n", s, len, nchars, strlen(s)); */
/* 	free(s); */
/* 	return (0); */
/* } */

/**
 * _getline - custom getline function
 * Description: function reads input from stdin
 *
 * @lineptr: address of text buffer
 * @n: number of bytes to read
 * @stream: FILE stream to read from
 *
 * Return: ssize_t, number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nrd, len_ptr = 0, i = 0;
	size_t BLK_SIZE = 512;
	int fdes;
	char rbuf[BLK_SIZE];

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BLK_SIZE * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
		*n = BLK_SIZE;
	}
	fdes = _fileno(stream);
	do {
		nrd = read(fdes, rbuf, BLK_SIZE);
		if (nrd <= 0)
		{
			if (len_ptr >  0)
				(*lineptr)[len_ptr] = '\0';
			return (-1);
		}
		if ((*n - len_ptr) <= (size_t)nrd)
		{
			*n = len_ptr + BLK_SIZE + 1;
			*lineptr = realloc(*lineptr, sizeof(char) * len_ptr, sizeof(char) * (*n));
			if (*lineptr == NULL)
				return (-1);
		}
		for (i = 0; i < nrd && (rbuf[i] != '\n' && rbuf[i] != '\r'); i++, len_ptr++)
			(*lineptr)[len_ptr] = rbuf[i];

		if (rbuf[i] == '\n' || rbuf[i] == '\r')
		{
			(*lineptr)[len_ptr] = '\0';
			return (len_ptr);
		}
	} while (nrd > 0);
	return (len_ptr);
}

/**
 * _fileno - returns the file descriptor associated with a file
 * Description: takes a FILE struct pointer and return the file descriptor
 * associated with the file
 *
 * @stream: FILE stream / filename
 *
 * Return: void
 */
int _fileno(FILE *stream)
{
	return (stream->_fileno);
}
