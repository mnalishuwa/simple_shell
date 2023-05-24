#include "main.h"

/**
 * main - test _strtok
 */

/* int main(void) */
/* { */
/* 	size_t len_s = 0, len_s2 = 0, i = 0; */
/* 	char s[] = "     ls la myfolder myfolder folder\t\t     ", *cln_s, **s2; */

/* 	/\* s = "       Hello\t  World\t\t     "; *\/ */
/* 	/\* s = "     ls la myfolder myfolder folder\t\t     "; *\/ */
/* 	len_s = strlen(s); */
/* 	printf("s initial = %s, len_s = %lu\n", s, len_s); */
/* 	cln_s = normalize_wspace(s, len_s); */
/* 	len_s2 = strlen(cln_s); */
/* 	/\* s3 = strdup(cln_s); *\/ */
/* 	printf("s normalized result = %s, len_s = %lu\n\n", cln_s, len_s2); */
/* 	s2 = _strtok(cln_s, " "); */
/* 	for (i = 0; s2[i] != NULL; i++) */
/* 	{ */
/* 		printf("args [%lu] = %s\n", i, s2[i]); */
/* 		if (s2[i] != NULL) */
/* 			free(s2[i]); */
/* 	} */

/* 	free(cln_s); */
/* 	free(s2); */
/* 	return (0); */
/* } */

/**
 * _strtok - parses a string into a sequence of tokens
 * Description: splits a string into tokens based on a delimeter
 * It dynamically allocates memory, therefore the caller must free
 * the memory after use.
 *
 * @_str: string arg
 * @_delim: string, delimiter
 *
 * Return: pointer to an array of string tokens or NULL otherwise
 */
char **_strtok(char *_str, const char *_delim)
{
	char **args = NULL;
	char *begin = NULL, *end, *dptr;
	size_t wlength, wcnt = 0, dlength, slength;

	if (_str == NULL || _delim == NULL)
	{
		perror("error: _strtok passed null\n");
		return (NULL);
	}
	begin = _str; /* pointer to hold beginning of token */
	end = _str; /* pointer to hold end of token */
	dlength = _strlen((char *)_delim); /* delimiter length */
	slength = _strlen(_str);

	dptr = _strstr(begin, (char *)_delim); /* match first token */
	while (dptr != NULL)
	{
		*dptr = '\0'; /* terminate token with null*/
		end = dptr; /* set end of token*/
		args = _realloc(args, sizeof(char *) * wcnt, sizeof(char *) * (wcnt + 1));
		wlength = (end - begin) + 1; /* get size of token + null byte*/
		args[wcnt] = malloc(sizeof(char) * wlength); /* allocate for token */
		_strncpy(args[wcnt], begin, wlength); /* copy token to args */
		wcnt++; /* increment the number of words/tokens*/
		if ((slength - (end - _str)) > dlength)
		{/* move ptr to end of delimiter, _strstr returns at start of substring*/
			dptr += dlength;
		}
		begin = dptr; /* set begin to start of next token*/
		dptr = _strstr(begin, (char *)_delim); /* search for next token */
	}
	args = _realloc(args, sizeof(char *) * wcnt, sizeof(char *) * (wcnt + 1));
	wlength = _strlen(begin) + 1;
	args[wcnt] = malloc(sizeof(char) * wlength);
	_strncpy(args[wcnt], begin, wlength);
	wcnt++;
	args = _realloc(args, sizeof(char *) * wcnt, sizeof(char *) * (wcnt + 1));
	args[wcnt] = NULL;

	return (args);
}

/**
 * normalize_wspace - removes all extra spaces from a string
 * Description: takes a string and removes any extra, or
 * consecutive spaces from the string.
 *
 * @_str: string arg
 * @len_s: string length
 *
 * Return: string
 */
char *normalize_wspace(char *_str, size_t len_s)
{
	char *cln_str;
	size_t i = 0, j = 0;

	cln_str = malloc(sizeof(char) * (len_s + 2));
	/* loop through to end of input string */
	for (i = 0, j = 0; _str[i] != '\0'; j++, i++)
	{
		if (_str[i] == ' ' || _str[i] == '\t' || _str[i] == '\v')
		{/* if whitespace is matched */
			if (i != 0)
			{/*only copy a single ' ' to normalized string*/
				cln_str[j] = ' ';
				i++;
				j++;
			}
			while (_str[i] == ' ' || _str[i] == '\t' || _str[i] == '\v')
			{/* loop through and ignore all other spaces*/
				i++;
			}
		}
		cln_str[j] = _str[i]; /*copy non-whitespace char to normalized string*/
	}
	cln_str[j] = '\0';
	del_twspace(cln_str);

	return (cln_str);
}

/**
 * del_twspace - get rid of trailing whitespace
 * Description: removes any extra spaces at the end of a string
 *
 * @s: string input
 *
 * Return: void
 */
void del_twspace(char *s)
{
	size_t i = 0;
	int last_char = -1;

	if (s == NULL)
	{
		perror("error: del_twspace passed null\n");
		return;
	}
	while (s[i] != '\0')
	{/* find the last char, ignoring any whitespace */
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			last_char = i;
		i++;
	}
	s[last_char + 1] = '\0'; /* set char after last char to null */
}
