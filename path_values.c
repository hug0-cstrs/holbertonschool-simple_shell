#include "simple_shell.h"

/**
 * _strcmp - function that compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: an int:
 * 0, if the s1 and s2 are equal;
 * a negative value if s1 is less than s2;
 * a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			return (res);
		}
	}
	return (res);
}

/**
 * get_path - get the PATH environment variable value in one single string
 * @envp: an array of pointers with environment variables of the system
 *
 * Return: a pointer to a copy of the PATH environment variable value
 */
char *get_path(char *envp[])
{
	int i = 0;
	char *token_name = NULL;
	char *token_value = NULL;
	char *temp = NULL;
	char *path_name = "PATH";
	char *token_value_cp = NULL;

	while (envp[i] != NULL)
	{
		temp = strdup(envp[i]);
		token_name = _strtok(temp, "=");
		if ((_strcmp(token_name, path_name)) == 0)
		{
			token_value = _strtok(NULL, "=");
			break;
		}
		free(temp);
		i++;
	}
	token_value_cp = strdup(token_value);
	free(temp);

	return (token_value_cp);
}

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
