#include "simple_shell.h"

ssize_t _getline(char **line, size_t *linesize, FILE *stream)
{
	char buffer[128];

	if (line == NULL || linesize == NULL || stream == NULL)
	{
		printf("Error: Bad argument or stream pointer\n");
		return (-1);
	}

	/* On alloue de la mémoire pour la ligne qu'on lit */
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

	/* on initialise la ligne lue */
	(*line)[0] = '\0';

	/* On fait une petite boucle de lecture pour la la ligne */
	while (fgets(buffer, *linesize, stdin))
	{
		/* on vérifie la taille de la ligne lue */
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

		/* Permet de concaténer la ligne lue avec la ligne en cours de construction */
		strcat(*line, buffer);

		/* condition qui permet degérer de la fin de la ligne lue */
		if ((*line)[strlen(*line) - 1] == '\n')
		{
			(*line)[strlen(*line) - 1] = '\0'; /* On supprime le caractère '\n' */
			return (strlen(*line));
		}
	}

	return (-1);
}
