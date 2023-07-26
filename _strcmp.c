#include "main.h"


/**
 * _strcmp - compares two strings s1 and s2
 * Description: function compares the two strings s1 and s2. The locale is not
 * taken It returns an integer less than, equal to, or greater than zero if
 * s1 is found, respectively, to be less than, to match, or be greater than s2.
 * It uses ascii values for comparison, returns 0 if ascii values for a
 * character match.
 *
 * @s1: first string for comparison
 * @s2: second string for the comparison
 *
 * Return: int less than 0, or greater than 0 if all characters in the strings
 * match, 0 otherwise
 */

int _strcmp(char *s1, char *s2)
{

	int char_pos, len_s1, len_s2, shrt;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	shrt = len_s1;

	if (len_s1 > len_s2)
		shrt = len_s2;
	for (char_pos = 0; char_pos < shrt && *(s1 + char_pos) != '\0'; char_pos++)
	{
		if (*(s1 + char_pos) - *(s2 + char_pos) != 0)
			return (*(s1 + char_pos) - *(s2 + char_pos));
	}

	if (len_s1 != len_s2)
	{
		if (len_s1 > len_s2)
			return (1);
		return (-1);
	}
	return (0);
}
