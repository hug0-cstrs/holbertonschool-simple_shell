#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str)
{
	char *str_cp = strdup(str);
	char *token = NULL;
	char **array_of_words;
	int nb_words = 0;
	int i = 0, j = 0;

	for (; str_cp[i] != '\0'; i++)
	{
		if (str_cp[i] == ' ' && str_cp[i + 1] != ' ')
			nb_words++;
	}

	if (nb_words == 0)
	{
		printf("Add string\n");
		free(str_cp);
		exit(-1);
	}
	nb_words += 1;

	array_of_words = malloc(sizeof(char *) * nb_words);
	if (array_of_words == NULL)
	{
		free(str_cp);
		return (0);
	}

	token = strtok(str_cp, " ");

	for (i = 0; i < nb_words; i++)
	{
		array_of_words[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (array_of_words[i] == NULL)
		{
			for (; j < i; j++) // Libérer la mémoire allouée pour les chaînes précédentes
				free(array_of_words[j]);
			free(array_of_words);
			array_of_words = NULL;
			free(str_cp);
			return (0);
		}
		strcpy(array_of_words[i], token);
		printf("%s\n", array_of_words[i]);
		token = strtok(NULL, " ");
	}
	free(str_cp);
	return (array_of_words);
}

int main(void)
{
	char *str = "Vlad Hugo Axel Benjmain";
	char **words = NULL;
	int i = 0;

	words = split_string(str);

	for (; words[i] != NULL; i++)
		free(words[i]);
	free(words);

	return (0);
}
