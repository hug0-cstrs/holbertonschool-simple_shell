#include <stddef.h>

/**
 * is_delim - a function that checks if a character is delimiter
 * @c: the character to chel
 * @delim: a string of delimiters
 *
 * Return: 1 if a character is a delimiter, if not 0
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - a function that isolates sequential tokens in
 * a null-terminated string
 * @src: string to isolate tokens from
 * @delim: a string of delimiters
 *
 * Description: The first time that strtok() is called src should be specified;
 * subsequent calls, wishing to obtain further tokens from the same string,
 * should pass a null pointer instead. The separator string, delim,
 * must be supplied each time, and may change between calls.
 *
 * Return: return a pointer to the beginning of each subsequent token
 * in the string, after replacing the token itself with a NUL character.
 * When no more tokens remain, a null pointer is returned.
 */
char *_strtok(char *src, char *delim)
{
	/*start of the next search*/
	static char *backup_string;
	char *token = NULL;

	if (!src)
		src = backup_string;

	if (!src)
		return (NULL);

	/* ignore delims at the beginning of the string */
	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++;
			continue;
		}
		if (*src == '\0')
			return (NULL);
		break;
	}
	token = src;
	while (1)
	{
		if (*src == '\0')
		{
			backup_string = src;
			return (token);
		}
		if (is_delim(*src, delim))
		{
			*src = '\0';
			backup_string = src + 1;
			return (token);
		}
		src++;
	}
}
