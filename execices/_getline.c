#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

ssize_t _getline(char **line, size_t *linesize, FILE *stream)
{
	char buffer[128];

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

	while (fgets(buffer, *linesize, stdin))
	{
		if (*linesize - strlen(*line) < *linesize)
		{
			*linesize *= 2;
			*line = realloc(*line, *linesize);
			if (*line == NULL)
			{
				printf("Memory reallocation error\n");
				free(line);
				return (-1);
			}
		}
		strcat(*line, buffer);

		/*A virer le \n et le remplacer par \0 --> string terminée par \0\0*/
		// if ((*line)[strlen(*line) - 1] == '\n')
		// return (strlen(*line));

		 //code adapter pour super_simple shell :
		if ((*line)[strlen(*line) - 1] == '\n')
		{
			(*line)[strlen(*line) - 1] = '\0'; /* On supprime le caractère '\n' */
			return (strlen(*line));
		}
	}

	return (-1);
}
