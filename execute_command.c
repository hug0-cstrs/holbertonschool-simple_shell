#include "simple_shell.h"

/**
 * execute_command - function that executes a command
 * @command: string containing the command to execute
 * @path_values: An array of strings containing the path values
 *
 * Description: This function takes in the command entered by the user and
 * the path values and executes the command by forking a child process and
 * calling the execve() system call. It also checks if the entered command
 * is a valid path and if not, it searches the path values for the command.
 * If the command is not found in the path values,
 * it prints "Unknown command" and returns -1. After execution, it frees the
 * memory allocated for strcat.
 *
 * Return: Returns 1 on successful execution, -1 on failure
 */
int execute_command(char *command, char **path_values)
{
	char *args_array[256];
	int i = 0, j = 0, execve_res = 0;
	pid_t pid;
	int status;
	struct stat st; /*<------------*/
	int flag = 0;	/*<-------------*/
	char *strcat = NULL;
	char *arg = _strtok(command, " ");

	if (arg == NULL)
	{
		free(arg);
		return (-1);
	}

	while (arg != NULL)
	{
		args_array[i++] = arg;
		arg = _strtok(NULL, " ");
	}
	args_array[i] = NULL;

	/*-----------------------------------------*/

	if (*args_array[0] == '/')
	{
		if (stat(args_array[0], &st) == 0)
			flag = 1;
		else
		{
			printf("Unknown path\n");
			return (-1);
		}
	}
	else
	{
		while (path_values[j])
		{
			strcat = _strcatcp(path_values[j], args_array[0]);
			if (stat(strcat, &st) == 0)
			{
				flag = 2;
				break;
			}
			else
			{
				j++;
				flag = 0;
				free(strcat);
				continue;
			}
			free(strcat);
		}
	}
	/*-----------------------------------------*/
	if (flag)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error: child process failed");
			exit(1);
		}
		else if (pid == 0)
		{
			if (flag == 1)
				execve_res = execve(args_array[0], args_array, NULL);
			else if (flag == 2)
				execve_res = execve(strcat, args_array, NULL);
			if (execve_res == -1)
				return (-1);
		}
		else
		{
			wait(&status);
			if (flag == 2)
				free(strcat);
			return (1);
		}
	}
	if (!flag)
		printf("Unknown command\n");

	return (1);
}
