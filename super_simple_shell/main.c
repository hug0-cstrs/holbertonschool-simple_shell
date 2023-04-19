#include "simple_shell.h"

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
	}

	return 0;
}
