#include "simple_shell.h"
/**
 * main - Simple Shell simulation program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 * @envp: An array of strings containing the environment variables
 *
 * Description: Displays a prompt (here empty)
 * and waits for the user to type a command.
 * The command lines are simple, no semicolons, no pipes,
 * no redirections or any other advanced features.
 * If an executable cannot be found, prints an error message
 * and display the prompt again.
 *
 * Return: 127 if no environment defined, if PATH1 environment variable
 * defined, if PATH variable is an empty string or if the command is not found.
 * If no errors, the program returns 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	int path1 = search_path1(envp), execute = 0;
	char *command = NULL, *path = get_path(envp);
	size_t command_size = 0;
	ssize_t getline_result;
	char **path_values = get_path_values(path);

	(void)argc;
	while (1)
	{
		getline_result = _getline(&command, &command_size, stdin);
		if (getline_result == -1)
			continue;
		else if (getline_result == -2)
			break;

		execute = execute_command(path_values, command, argv, path);
		free(command);
		command = NULL;
	}
	free(command);
	command = NULL;
	if (path != NULL)
		free(path);
	if (path1 == -1 || path1 == 1 || execute == 0)
	{
		free_args_array(path_values);
		return (127);
	}
	if ((path_values != NULL && *path_values[0] == '\0'))
	{
		free_args_array(path_values);
		return (127);
	}
	free_args_array(path_values);
	return (0);
}
