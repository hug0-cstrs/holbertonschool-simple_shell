#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

ssize_t _getline(char **line, size_t *linesize, FILE *stream);

int main(void)
{

	int read;
	char *line = NULL;
	size_t size = 0;

	printf("$ ");
	read = _getline(&line, &size, stdin);
	if (read != -1)
		printf("%s", line);

	free(line);

	return (0);
}
