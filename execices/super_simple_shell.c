#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char *_strtok(char *src, char *delim);

/* lit une ligne de texte sur l'entrée standard */
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

void execute_command(char *command)
{
	char *args_array[256]; /* un petit tableau d'arguments, là j'ai décide de mettre 255 arguments */
	int i = 0;	       /* un petit compteur pour les arguments pour le kiff */
	pid_t pid;	       /* le PID du processus */
	int status;	       /* le status du processus enfant */

	/* On découpe la commande en arguments */
	char *arg = _strtok(command, " "); /* Pour le découpage de la commande en arguments, ici on utiliser l'espace comme séparateur (mais on pourrais mettre d'autre séparateur) */
	while (arg != NULL)		  /* boucle tant qu'il reste des arguments */
	{
		args_array[i++] = arg;	 /* On ajoute l'argument au tableau d'arguments et on incrémentation notre petit compteur */
		arg = _strtok(NULL, " "); /* ensuite on va récupérer l'argument suivant */
	}
	args_array[i] = NULL; /* On définit la dernière case du tableau d'arguments à NULL pour indiquer la fin des arguments */

	/* Ici on va créer un processus fils pour exécuter la commande */
	pid = fork(); /* du coup on créer un processus fils */
	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	else if (pid == 0) /* code exécuté par le processus fils */
	{
		/* Le processus fils exécute la commande */
		if (execve(args_array[0], args_array, NULL) == -1)
		{
			perror("Error:");
			exit(1);
		}
	}
	else /* code exécuté par le processus parent */
	{
		wait(&status); /* Le processus du père attend attente de la fin de l'exécution du processus fils */
	}
}

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;

	while (1)
	{
		/* Affichage du prompt */
		printf("Vlad@Hugo$ ");

		/* Lecture de la commande */
		if (_getline(&command, &command_size, stdin) == -1)
		{
			printf("Error: Failed to read command\n");
			continue;
		}

		/* Exécution de la commande */
		execute_command(command);

		/* Libération de la mémoire allouée pour la commande */
		free(command);
		command = NULL;
		command_size = 0;
	}

	return 0;
}
