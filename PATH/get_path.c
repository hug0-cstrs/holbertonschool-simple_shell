#include "simple_shell.h"

int get_path(char *envp[])
{
	int i = 0;
	char *token_name;
	char *token_value;
	char *temp;
	char *path = "PATH";

	while (envp[i] != NULL)
	{
		temp = strdup(envp[i]);
		token_name = _strtok(temp, "=");
		if ((_strcmp(token_name, path)) == 0)
		{
			printf("%s", token_name);
			token_value = _strtok(NULL, "=");
			printf("---->%s\n", token_value);
		}
		free(temp);
		i++;
	}
	return 0;
}
