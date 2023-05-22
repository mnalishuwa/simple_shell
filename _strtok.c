#include "main.h"

/**
 * main - test _strtok
 */

int main(void)
{
	size_t len_s = 0, len_s2 = 0, i = 0;
	char s[] = "     ls la myfolder myfolder folder\t\t     ", *cln_s, **s2;

	//s = "       Hello\t  World\t\t     ";
    //s = "     ls la myfolder myfolder folder\t\t     ";
	len_s = strlen(s);
	printf("s initial = %s, len_s = %lu\n", s, len_s);
	cln_s = normalize_wspace(s, len_s);
	len_s2 = strlen(cln_s);
    //s3 = strdup(cln_s);
	printf("s normalized result = %s, len_s = %lu\n\n", cln_s, len_s2);
	s2 = _strtok(cln_s, " ");
    for (i = 0; s2[i] != NULL; i++)
    {
        printf("args[%lu] = %s\n", i, s2[i]);
		if (s2[i] != NULL)
			free(s2[i]);
    }

	free(cln_s);
	free(s2);
	return (0);
}

/* int main(void) */
/* { */
/* 	size_t i = 0; */
/* 	/\* char s1[] = "Geeks1 for Greeks2 for The Geeks3 for Geeks4"; *\/ */
/* 	/\* char s1[] = "parses a string into a sequence of tokens"; *\/ */
/* 	char s1[] = "ls -la myfolder1 myfolder2 myfolder3"; */
/* 	char s2[] = " "; */
/* 	char **argvec = _strtok(s1, s2); */

/* 	for (i = 0; argvec[i] != NULL; i++) */
/* 		printf("argv[%lu] = %s\n",i, argvec[i]); */
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
 * Return: pointer to the next token
 */
char **_strtok(char *_str, const char *_delim)
{
	char **args = NULL;
	char *begin, *end, *dptr;
	const char * __attribute__((unused)) _str2 = (const char *)_str;
	size_t wlength, wcount = 0, dlength, __attribute__((unused)) slength;

	begin = _str;
	end = _str;
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
		if ((slength - (end - _str)) > dlength)
		{
			dptr += dlength;
		}
		begin = dptr;
		dptr = strstr(begin, _delim);
	}

	if (wcount > 0)
	{
		args = realloc(args, sizeof(char *) * (wcount + 1));
		wlength = strlen(begin) + 1;
		args[wcount] = malloc(sizeof(char) * wlength);
		strncpy(args[wcount], begin, wlength);
		wcount++;
		args = realloc(args, sizeof(char *) * (wcount + 1));
		args[wcount] = NULL;
	}

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

	for (i = 0, j = 0; _str[i] != '\0'; j++, i++)
	{
		if (_str[i] == ' ' || _str[i] == '\t' || _str[i] == '\v')
		{
			if (i != 0)
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
    del_twspace(cln_str);

	return (cln_str);
}

/**
 * del_twspace - get rid of trailing whitespace
 * Description: removes any extra spaces at the end of a string
 *
 * Return: void
 */
void del_twspace(char *s)
{
    size_t i = 0;
    int last_char = -1;

	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			last_char = i;
		i++;
	}
	s[last_char + 1] = '\0';
}
