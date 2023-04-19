#include "simple_shell.h"

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t getline_result;

	while (1)
	{
		/* Affichage du prompt */
		printf("Vlad@Hugo$ ");

		/* Lecture de la commande */
		getline_result = _getline(&command, &command_size, stdin);
		if (getline_result == -1)
		{
			printf("Error: Failed to read command\n");
			continue;
		}
		else if (getline_result == -2)
			break;

		/* Exécution de la commande */
		execute_command(command);

		/* Libération de la mémoire allouée pour la commande */
		free(command);
		command = NULL;
	}
	free(command);
	command = NULL;
	
	return 0;
}
