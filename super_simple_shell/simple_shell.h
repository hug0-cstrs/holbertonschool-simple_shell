#ifndef SIMPLE_SHELL_H

#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_strtok(char *src, char *delim);
ssize_t _getline(char **line, size_t *linesize, FILE *stream);
void execute_command(char *command);

#endif
