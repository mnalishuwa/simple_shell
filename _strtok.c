#include "main.h"

/**
 * main - test _strtok
 */

/* int main(void) */
/* { */
/* 	size_t len_s, len_s2, i; */
/* 	char *s, /\* *s2, *\/ *s3, *s4, *cln_s; */

/* 	s = "       Hello\t  World\t\t     "; */
/* 	len_s = strlen(s); */
/* 	printf("s initial = %s, len_s = %lu\n", s, len_s); */
/* 	cln_s = normalize_wspace(s, len_s); */
/* 	len_s2 = strlen(s); */
/* 	printf("s result = %s, len_s = %lu\n\n", cln_s, len_s2); */
/* 	/\* s2 = _strtok(cln_s, ' '); *\/ */

/* 	s3 = "Geeks1 for Greeks2 for The Geeks3 for Geeks4"; */
/* 	s4 = " "; */
/* 	char **argvec = _strtok(s3, s4); */

/* 	for (i = 0; argvec[i] != NULL; i++) */
/* 		printf("argv = %s\n", argvec[i]); */

/* 	return (0); */
/* } */

int main(void)
{
	size_t i = 0;
	/* char s1[] = "Geeks1 for Greeks2 for The Geeks3 for Geeks4"; */
	/* char s1[] = "parses a string into a sequence of tokens"; */
	char s1[] = "ls -la myfolder1 myfolder2 myfolder3";
	char s2[] = " ";
	char **argvec = _strtok(s1, s2);

	for (i = 0; argvec[i] != NULL; i++)
		printf("argv[%lu] = %s\n",i, argvec[i]);
	return (0);
}
/**
 * _strtok - parses a string into a sequence of tokens
 * Description: splits a string into tokens based on a delimeter
 *
 * @_str; string arg
 * @_delim: string, delimiter
 *
 * Return: pointer to the next token
 */
char **_strtok(char *_str, const char *_delim)
{
	char **args = NULL;
	char *begin, *end, *dptr;
	size_t wlength, wcount = 0, dlength, __attribute__((unused)) slength;

	begin = end = _str;
	dlength = strlen(_delim);
	slength = strlen(_str);

	dptr = strstr(begin, _delim);
	while (dptr != NULL)
	{
		*dptr = '\0';
		end = dptr;
		args = realloc(args, sizeof(char *) * (wcount + 1));
		wlength = (end - begin) + 1;
		args[wcount] = malloc(sizeof(char) * wlength);
		strncpy(args[wcount], begin, wlength);
		wcount++;
		dptr += dlength;
		begin = dptr;
		dptr = strstr(begin, _delim);
	}
	args = realloc(args, sizeof(char *) * (wcount + 1));
	wlength = strlen(begin) + 1;
	args[wcount] = malloc(sizeof(char) * wlength);
	strncpy(args[wcount], begin, wlength);
	wcount++;
	args[wcount] = NULL;

	return (args);
}

/**
 * normalize_wspace - removes all extra spaces from a string
 * Description: takes a string and removes any extra, or
 * consecutive spaces from the string.
 *
 * @_str: string arg
 *
 * Return: string
 */
char *normalize_wspace(char *_str, size_t len_s)
{
	char *cln_str;
	size_t i, j;

	cln_str = malloc(sizeof(char) * (len_s + 1));

	for (i = 0, j = 0; _str[i] != '\0'; j++, i++)
	{
		if (_str[i] == ' ' || _str[i] == '\t' || _str[i] == '\v')
		{
			if (i != 0 && i != len_s - 1)
			{
				cln_str[j] = ' ';
				i++;
				j++;
			}
			while (_str[i] == ' ' || _str[i] == '\t' || _str[i] == '\v')
			{
				i++;
			}
		}

		cln_str[j] = _str[i];
	}
	cln_str[j] = '\0';

	return (cln_str);
}
