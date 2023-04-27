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
 * If the command is found as a valid paththe flag is set to 1. If the command
 * is found by searching the path values, the flag is set to 2. It returns the
 * full path of the command on success, NULL on failure.
 *
 * Return: Returns a pointer to a string containing the full path of the
 * command on success, NULL on failure.
 */
char *check_command(char **args_array, char **path_values, int *flag)
{
	char *strcat = NULL, *env = "env", *env_path = "/usr/bin";
	int j = 0;
	struct stat st;

	if (args_array == NULL)
		return (NULL);

	if (*args_array[0] == '/' || *args_array[0] == '.')
	{
		if (stat(args_array[0], &st) == 0)
			*flag = 1;
		else
			return (NULL);
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
			free(strcat);
		}
	}
	if ((_strcmp(args_array[0], env) == 0) && path_values == NULL)
	{
		strcat = _strcatcp(env_path, env);
		*flag = 2;
	}
	return (strcat);
}

/**
 * _fork - function that fork
 * @fl: flag to check command
 * @args_a: An array of strings containing command arguments
 * @strcat: a pointer to a string containing the full path of the command
 * @cmd: string containing the command to execute
 * @path_v: An array of strings containing the path values
 * @path: A pointer to a copy of the PATH environment variable value
 *
 * Description: exits with status 2 if bad arguments in the command
 * Return: Returns 1 on successful fork execution, -2 if fork fails or
 * -1 if execve fails
 */
int _fork(int fl, char **args_a, char *strcat, char *cmd,
char **path_v, char *path)
{
	pid_t pid;
	int execve_res = 0, status, exit_status;

	pid = fork();
	if (pid == -1)
		return (-2);
	else if (pid == 0)
	{
		if (fl == 1)
			execve_res = execve(args_a[0], args_a, environ);
		else if (fl == 2)
			execve_res = execve(strcat, args_a, environ);
		if (execve_res == -1)
			return (-1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status)) /* 1 if child executed normally */
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0) /* if non null, means error at execution */
			{
				if (fl == 2)
					_free(cmd, args_a, path_v, path, strcat);
				else if (fl == 1)
					_free(cmd, args_a, path_v, path, NULL);
				exit(2);
			}
		}
		if (fl == 2)
			_free(NULL, args_a, NULL, NULL, strcat);
		else if (fl == 1)
			free_args_array(args_a);
		return (1);
	}
	return (0);
}

/**
 * execute_command - function that executes a command
 * @command: string containing the command to execute
 * @path_values: An array of strings containing the path values
 * @argv: An array of strings containing the arguments passed to the program
 * @path: A pointer to a copy of the PATH environment variable value
 *
 * Description: This function takes in the command entered by the user and
 * the path values and executes the command by calling _fork function.
 *
 * Return: Returns 0 if PATH1 variable found or no valid command or PATH=""
 * and 2 on successful execution
 */
int execute_command(char **path_values, char *command, char **argv, char *path)
{
	int fl = 0, fork_res = 0;
	char **args_array = create_args_array(command), *_exit = "exit";
	char *strcat = check_command(args_array, path_values, &fl);
	int path1 = search_path1(environ);

	if (fl)
		fork_res = _fork(fl, args_array, strcat, command, path_values, path);
	if (fork_res == 0)
	{
		if (args_array != NULL && (_strcmp(args_array[0], _exit) == 0))
		{
			_free(command, args_array, path_values, path, NULL);
			exit(0);
		}
		if (path1 == -1)
		{
			if (args_array != NULL)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args_array[0]);
				free_args_array(args_array);
				return (0);
			}
		}
		if ((path_values != NULL && *path_values[0] == '\0')
		|| fl == 0 || path1 == 1)
		{
			if (args_array != NULL)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args_array[0]);
				free_args_array(args_array);
				return (0);
			}
		}
	}
	return (2);
}
