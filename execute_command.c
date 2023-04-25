#include "simple_shell.h"
/**
 * create_args_array - function that creates an array of arguments
 * from a command string
 * @command: string containing the command to execute
 *
 * Description: This function takes in a command string and tokenizes it using
 * the delimiter " " to create an array of arguments. It allocates memory for
 * the arguments array and each argument using malloc(). The last element of
 * the array is set to NULL. If the command string is empty or allocation fails
 * it returns NULL.
 *
 * Return: Returns a pointer to the array of arguments on success,
 * NULL on failure
*/
char **create_args_array(char *command)
{
	int i = 0;
	char **args_array = NULL;
	char *arg = NULL;

	arg = _strtok(command, " ");
	if (arg == NULL)
		return (NULL);

	args_array = malloc(sizeof(char *) * 256);
	if (args_array == NULL)
		return (NULL);

	while (arg != NULL)
	{
		args_array[i++] = strdup(arg);
		arg = _strtok(NULL, " ");
	}
	args_array[i] = NULL;

	return (args_array);
}

/**
 * check_command - function that checks if a command exists and is executable
 * @args_array: array of arguments for the command
 * @path_values: An array of strings containing the path values
 * @flag: pointer to an integer to determine the execution mode of the command
 *
 * Description: This function takes in an array of arguments for a command and
 * an array of path values. It checks if command is a valid path by checking
 * if the first character is "/". If it is not a valid path, it searches the
 * path values for command by concatenating each path value with the command
 * name. It uses stat() system call to check if the command exists and is
 * executable.
 * If the command is not found, it prints "Unknown command" and returns NULL.
 * If the command is found as a valid paththe flag is set to 1. If the command
 * is found by searching the path values, the flag is set to 2. It returns the
 * full path of the command on success, NULL on failure.
 *
 * Return: Returns a pointer to a string containing the full path of the
 * command on success, NULL on failure.
*/
char *check_command(char **args_array, char **path_values, int *flag)
{
	char *strcat = NULL;
	int j = 0;
	struct stat st;

	if (args_array == NULL)
		return (NULL);

	if (*args_array[0] == '/' || *args_array[0] == '.')
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
		while (path_values != NULL && path_values[j])
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
			free(strcat); /*?????*/
		}
	}

	return (strcat);
}
/**
 * free_args_array - function that free memory allocated for an arguments array
 * @args_array: array of arguments to free
 *
 * Description: This function takes in an array of arguments and frees
 * the memory
 * allocated for each argument and the array itself using free().
 * If the arguments
 * array is empty, it does nothing.
 *
 * Return: void
*/
void free_args_array(char **args_array)
{
	int i = 0;

	if (args_array != NULL)
	{
		while (args_array[i])
		{
			free(args_array[i]);
			i++;
		}
	free(args_array);
	}
}

/**
 * execute_command - function that executes a command
 * @command: string containing the command to execute
 * @path_values: An array of strings containing the path values
 * @argv: An array of strings containing the arguments passed to the program
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
int execute_command(char **path_values, char *command, char **argv)
{
	int execve_res = 0, status, flag = 0;
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
				execve_res = execve(args_array[0], args_array, environ);
			else if (flag == 2)
				execve_res = execve(strcat, args_array, environ);
			if (execve_res == -1)
				return (-1);
		}
		else
		{
			wait(&status);
			if (flag == 2)
			{
				free_args_array(args_array);
				free(strcat);
			}
			else if (flag == 1)
				free_args_array(args_array);
			return (1);
		}
	}

	if (!environ || (path_values != NULL && *path_values[0] == '\0'))
	{
		if (args_array != NULL)
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args_array[0]);
	}

	if (args_array != NULL)
		free_args_array(args_array);
	
	return (1);
}
