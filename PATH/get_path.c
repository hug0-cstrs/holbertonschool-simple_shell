#include "simple_shell.h"

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
