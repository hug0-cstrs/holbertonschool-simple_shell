#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *_strtok(char *src, char *delim);

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

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	char *token_name = NULL;
	char *token_value = NULL;
	char *temp = NULL;
	char *path_name = (char*) name;
	char *token_value_cp = NULL;
	char **envp = environ;

	while (envp[i] != NULL)
	{
		temp = strdup(envp[i]);
		token_name = _strtok(temp, "=");
		if ((_strcmp(token_name, path_name)) == 0)
		{
			token_value = _strtok(NULL, "=");
			break;
		}
		else
		{
			printf("Not found\n");
			return (NULL);
		}
		free(temp);
		i++;
	}
	token_value_cp = strdup(token_value);
	free(temp);

	return (token_value_cp);
}

int main (void)
{
	char *env_name = "HUGO";
	char *env_value = _getenv(env_name);

	printf("Environnement name: %s, environnement value: %s\n", env_name, env_value);

	return (0);
}
