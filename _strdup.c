#include "main.h"

/**
 * _strdup - duplicates a string
 * Description: takes a string as an argument and returns
 * a pointer to a copy of the string
 *
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	char *str_cpy; /* pointer to str copy */
	int len_s; /* get str length */
	int i;

	if (!str)
		return (NULL);

	len_s = _strlen(str);

	/* allocate memory */
	str_cpy = malloc((len_s + 1) * sizeof(char));

	/* check if malloc() failed */
	if (str_cpy == NULL)
		return (NULL);

	/* duplicate string into str_copy */
	for (i = 0; i < len_s; i++)
		str_cpy[i] = str[i];
	str_cpy[i] = '\0';

	return (str_cpy);
}
