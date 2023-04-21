#include "simple_shell.h"

int main(int argc, char *argv[], char *envp[])
{
	char *token_value = get_path(envp);
	char **path_values = get_path_values(token_value);
	int i = 0;

	(void)argc;
	(void)argv;
	
	while (path_values[i])
	{
		printf("%s\n", path_values[i]);
		free(path_values[i]);
		i++;
	}	

	free(token_value);
	free(path_values);

	return (0);
}
