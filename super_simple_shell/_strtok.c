#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function to find delimiter*/
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return 1;
		delim++;
	}
	return 0;
}

/*Own implementation of strtok*/
char *_strtok(char *src, char *delim)
{
	/*start of the next search*/
	static char *backup_string;
	char *token = NULL;

	if (!src)
		src = backup_string;

	if (!src)
		return NULL;

	/* ignore delims at the beginning of the string */
	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++;
			continue;
		}
		if (*src == '\0')
			return NULL;
		break;
	}
	token = src;
	while (1)
	{
		if (*src == '\0')
		{
			backup_string = src;
			return token;
		}
		if (is_delim(*src, delim))
		{
			*src = '\0';
			backup_string = src + 1;
			return token;
		}
		src++;
	}
}
