#include "main.h"

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
	ssize_t nread;
	size_t len = 0;

	nread = _getline(&_lineptr, &len, stdin);
	eof_handler(nread, errno, _lineptr);

	if (nread == -1 && (errno == ENOMEM || errno == EINVAL))
	{
		perror("error: read_line failed:");
		return (NULL);
	}
	if (_lineptr[nread - 1] == '\n')
		_lineptr[nread - 1] = '\0';

	return (_lineptr);
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
	len_s = _strlen(_str);
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
		perror("error: strip, memory allocation failed:");
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
