#include "simple_shell.h"

/**
 * _getline - get a line from a stream
 * @line: a pointer to a malloced buffer for the line
 * @linesize: the capacity of that buffer
 * @stream: stream to read the line from
 *
 * Description: reads a line from stream, delimited by the newline character
 * Return: return the number of characters written, excluding the terminating
 * NUL character.  The value -1 is returned if an error occurs,
 * or -2 if end-of-file is reached.
 */

ssize_t _getline(char **line, size_t *linesize, FILE *stream)
{
	char buffer[128];
	ssize_t chars_read = 0;
	ssize_t total_chars = 0;

	if (line == NULL || linesize == NULL || stream == NULL)
	{
		printf("Error: Bad argument or stream pointer\n");
		return (-1);
	}

	if (*line == NULL)
	{
		*linesize = sizeof(buffer);
		*line = malloc(*linesize);
		if (*line == NULL)
		{
			printf("Memory allocation error\n");
			return (-1);
		}
	}

	(*line)[0] = '\0';
	while (fgets(buffer, sizeof(buffer), stream))
	{
		chars_read = strlen(buffer);

		/* Check line size and reallocate memory if too long */
		while (*linesize - total_chars < (ssize_t)chars_read)
		{
			*linesize *= 2;
			*line = realloc(*line, *linesize);
			if (*line == NULL)
			{
				printf("Memory reallocation error\n");
				return (-1);
			}
		}

		strcat(*line, buffer);
		total_chars += chars_read;

		if ((*line)[total_chars - 1] == '\n')
		{
			(*line)[total_chars - 1] = '\0';
			return total_chars;
		}
	}

	if (feof(stream))
	{
		return (total_chars > 0) ? total_chars : -2;
	}
	else
	{
		return -1;
	}
}
