#include "simple_shell.h"

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
 * _free - function that frees strings and arrays of strings
 * @cmd: string containing the command to execute
 * @args_a: An array of strings containing command arguments
 * @path_v: An array of strings containing the path values
 * @path: A pointer to a copy of the PATH environment variable value
 * @strcat: a pointer to a string containing the full path of the command
 *
 * Return: Nothing
 */
void _free(char *cmd, char **args_a, char **path_v, char *path, char *strcat)
{
	if (cmd != NULL)
		free(cmd);
	free_args_array(args_a);
	free_args_array(path_v);
	if (path != NULL)
		free(path);
	if (strcat != NULL)
		free(strcat);
}
