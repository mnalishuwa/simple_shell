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
 * Return: ssize_t, number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nread, len_ptr, i = 0;
	size_t BLK_SIZE = 512;
	int fdes;
	char _rd_buf[BLK_SIZE], __attribute__((unused)) *newptr;

	if (*lineptr == NULL || *n == 0)
	{
		newptr = malloc(BLK_SIZE * sizeof(char));
		if (newptr == NULL)
			return (-1);
		*lineptr = newptr;
		*n = BLK_SIZE;
	}

	fdes = _fileno(stream);
	len_ptr = 0;
	do
	{
		nread = read(fdes, _rd_buf, BLK_SIZE);
		if (nread <= 0)
		{
			if (len_ptr >  0)
				(*lineptr)[len_ptr] = '\0';
			return (-1);
		}

		if ((*n - len_ptr) <= (size_t)nread)
		{
			*n = len_ptr + BLK_SIZE + 1;
			*lineptr = realloc(*lineptr, sizeof(char) * (*n));
			if (*lineptr == NULL)
				return (-1);
		}

		i = 0;
		while (i < nread && (_rd_buf[i] != '\n' && _rd_buf[i] != '\r'))
		{
			(*lineptr)[len_ptr] = _rd_buf[i];
			i++;
			len_ptr++;
		}

		if (_rd_buf[i] == '\n' || _rd_buf[i] == '\r')
		{
			(*lineptr)[len_ptr] = '\0';
			return (len_ptr);
		}

	} while (nread > 0);

	return (len_ptr);
}

/**
 * _fileno - returns the file descriptor associated with a file
 * Description: takes a FILE struct pointer and return the file descriptor
 * associated with the file
 *
 * Return: void
 */
int _fileno(FILE *stream)
{
	return (stream->_fileno);
}
