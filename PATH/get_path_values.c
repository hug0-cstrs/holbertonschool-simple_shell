#include "simple_shell.h"

/**
 * get_path_values - stores PATH value in an arrays table
 * @token_value: string containing PATH variable value in one string
 *
 * Return: a pointer to an array table containing all PATH values one by one
 */
char **get_path_values(char *token_value)
{
	int j = 0, i = 0;
	char *token = NULL;
	char **path_values = NULL;
	char *temp = NULL;

	/*Get number of list of directories in PATH variable */
	temp = strdup(token_value);
	token = _strtok(temp, ":");
	while (token != NULL)
	{
		token = _strtok(NULL, ":");
		j++;
	}

	path_values = malloc(sizeof(char *) * (j + 1));
	if (path_values == NULL)
	{
		printf("Memory allocation error\n");
		return (NULL);
	}

	i = 0;
	token = _strtok(token_value, ":");
	while (token != NULL)
	{
		path_values[i] = strdup(token);
		token = _strtok(NULL, ":");
		i++;
	}
	path_values[i] = NULL;

	free(temp);
	return (path_values);
}
