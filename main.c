#include "simple_shell.h"
/**
 * main - super simple shell program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 * @envp: An array of strings containing the environment variables
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
int main(int argc, char *argv[], char *envp[])
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t getline_result;
	char *path = NULL;
	char **path_values = NULL;
	(void)argc;
	path = get_path(envp);
	path_values = get_path_values(path);

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

		execute_command(path_values, command, argv);
		free(command);
		command = NULL;
	}
	
	free(command);
	command = NULL;

	if (path != NULL)
		free(path);

	if (!environ || (path_values != NULL && *path_values[0] == '\0'))
	{
		free_args_array(path_values);
		return (127);
	}
		
	free_args_array(path_values);

		
	return (0);
}
