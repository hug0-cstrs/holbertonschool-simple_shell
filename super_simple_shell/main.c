#include "simple_shell.h"

/**
 * main - super simple shell program
 *
 * Description: Displays a prompt and waits for the user to type a command.
 * A command line always ends with a new line.
 * The prompt is displayed again each time a command has been executed.
 * The command lines are simple, no semicolons, no pipes,
 * no redirections or any other advanced features.
 * The command lines are made only of one word.
 * No arguments will be passed to programs.
 * If an executable cannot be found, prints an error message
 * and display the prompt again.
 * You have to handles the “end of file” condition (Ctrl+D)
 * No memory leaks
 *
 * Return: always 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t getline_result;

	while (1)
	{
		getline_result = _getline(&command, &command_size, stdin);

		if (getline_result == -1)
		{
			printf("Error: Failed to read command\n");
			continue;
		}
		else if (getline_result == -2)
		{
			break;
		}

		execute_command(command);

		free(command);
		command = NULL;
	}
	free(command);
	command = NULL;

	return (0);
}
