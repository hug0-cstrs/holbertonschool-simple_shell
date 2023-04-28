#ifndef SIMPLE_SHELL_H

#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_strtok(char *src, char *delim);
ssize_t _getline(char **line, size_t *linesize, FILE *stream);
int _strcmp(char *s1, char *s2);
char *get_path(char *envp[]);
char **get_path_values(char *token_value);
char *_strcatcp(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **create_args_array(char *command);
char *check_command(char **args_array, char **path_values, int *flag);
int execute_command(char **path_values, char *command,
char **argv, char *path);
void free_args_array(char **args_array);
int search_path1(char **environ);
void _free(char *cmd, char **args_a, char **path_v,
char *path, char *strcat);
int _fork(int fl, char **args_a, char *strcat, char *cmd,
char **path_v, char *path);

#endif
