#include "simple_shell.h"

/**
 * _strcmp - function that compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: an int:
 * 0, if the s1 and s2 are equal;
 * a negative value if s1 is less than s2;
 * a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			return (res);
		}
	}
	return (res);
}
