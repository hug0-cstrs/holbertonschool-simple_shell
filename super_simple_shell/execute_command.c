#include "simple_shell.h"

void execute_command(char *command)
{
	char *args_array[256]; /* un petit tableau d'arguments, là j'ai décide de mettre 255 arguments */
	int i = 0;
	int j = 0;	       /* un petit compteur pour les arguments pour le kiff */
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
		for (j = 0; j < i; j++)
			free(args_array[i]);
		free(*args_array);
	}
}
