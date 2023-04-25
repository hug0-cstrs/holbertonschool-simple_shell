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
char *get_path(char *envp[], int *flag1)
{
	int i = 0;
	char *token_name = NULL;
	char *token_value = NULL;
	char *temp = NULL;
	char *path_name = "PATH";
	char *token_value_cp = NULL;
	char *path_name1 = "PATH1";

	while (envp[i] != NULL)
	{
		temp = strdup(envp[i]);
		token_name = _strtok(temp, "=");

		if ((_strcmp(token_name, path_name1)) == 0)
		{
			*flag1 = 1;
			return (NULL);
		}

		if ((_strcmp(token_name, path_name)) == 0)
		{
			token_value = _strtok(NULL, "=");
			if (token_value == NULL && *(temp + strlen(token_name) + 1) == '\0')
				token_value = "";
			break;
		}
		free(temp);
		i++;
	}
	if (token_value == NULL)
		return (NULL);
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
	char *empty_string = "";

	if (token_value == NULL)
		return (NULL);
	/*Get number of list of directories in PATH variable */
	temp = strdup(token_value);
	token = _strtok(temp, ":");
	while (token != NULL)
	{
		token = _strtok(NULL, ":");
		j++;
	}
	if (*token_value == '\0')
		path_values = malloc(sizeof(char *) * (j + 2));
	else
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
	if (i == 0)
	{
		path_values[i] = strdup(empty_string);
		path_values[i + 1] = NULL; 
	}
	else
		path_values[i] = NULL;

	free(temp);
	return (path_values);
}
