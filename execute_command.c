#include "simple_shell.h"

/**
 * execute_command - function that executes a command
 * @command: string containing the command to execute
 *
 * Description: delimits the command into tokens with _strtok function and
 * stores each separated string argument in an array. The execute_command
 * creates a new child process which executes the command with execve function
 * Return: nothing
 */

void execute_command(char *command)
{
	char *args_array[256];
	int i = 0;
	pid_t pid;
	int status;
	char *arg = _strtok(command, " ");

	while (arg != NULL)
	{
		args_array[i++] = arg;
		arg = _strtok(NULL, " ");
	}
	args_array[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: child process failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args_array[0], args_array, NULL) == -1)
		{
			perror("./shell: No such file or directory\n");
			exit(1);
		}
	}
	else
		wait(&status);
}
