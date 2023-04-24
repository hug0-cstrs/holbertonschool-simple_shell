#include "simple_shell.h"

char **create_args_array(char *command)
{
	int i = 0;
	char **args_array = NULL;
	char *arg = NULL;

	args_array = malloc(sizeof(char *) * 256);
	if (args_array == NULL)
		return (NULL);
	
	arg = _strtok(command, " ");
	if (arg == NULL)
	{
		/*free(arg);*/
		return (NULL);
	}

	while (arg != NULL)
	{
		args_array[i++] = arg;
		arg = _strtok(NULL, " ");
	}
	args_array[i] = NULL;

	return (args_array);
}

char *check_command(char **args_array, char **path_values, int *flag)
{
	char *strcat = NULL;
	int j = 0;
	struct stat st;

	if (*args_array[0] == '/')
	{
		if (stat(args_array[0], &st) == 0)
			*flag = 1;
		else
		{
			printf("Unknown path\n");
			return (NULL);
		}
	}
	else
	{
		while (path_values[j])
		{
			strcat = _strcatcp(path_values[j], args_array[0]);
			if (stat(strcat, &st) == 0)
			{
				*flag = 2;
				break;
			}
			else
			{
				j++;
				*flag = 0;
				free(strcat);
				continue;
			}
			free(strcat);
		}
	}

	return (strcat);
}

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
int execute_command(char **path_values, char *command)
{
	int execve_res = 0, status, flag = 0, i = 0;
	pid_t pid;
	char **args_array = create_args_array(command);
	char *strcat = check_command(args_array, path_values, &flag);

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
	while (args_array[i])
	{
		free(args_array[i]);
		i++;
	}
	free(args_array);
	return (1);
}
