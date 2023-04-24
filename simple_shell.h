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

/**
 * struct stat - Structure containing information about a file
 * @st_dev: Device ID of the device containing the file
 * @st_ino: Inode number of the file
 * @st_mode: File type and mode (permissions)
 * @st_nlink: Number of hard links to the file
 * @st_uid: User ID of the file owner
 * @st_gid: Group ID of the file owner
 * @st_rdev: Device ID (if file is a special file)
 * @st_size: Total file size, in bytes
 * @st_blksize: Block size for filesystem I/O
 * @st_blocks: Number of 512B blocks allocated for the file
 * @st_atime: Time of last access
 * @st_mtime: Time of last modification
 * @st_ctime: Time of last status change
 *
 * Description: The stat structure is used to store information about a file.
 * It is utilized by the stat(), fstat() and lstat() system calls to retrieve
 * information about the file such as its size, permissions, and creation time.
 * The structure contains fields such as the file's inode number, owner and
 * group IDs, protection mode, size, and timestamps.
 */
struct stat;

char *_strtok(char *src, char *delim);
ssize_t _getline(char **line, size_t *linesize, FILE *stream);
int _strcmp(char *s1, char *s2);
char *get_path(char *envp[]);
char **get_path_values(char *token_value);
char *_strcatcp(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **create_args_array(char *command);
char *check_command(char **args_array, char **path_values, int *flag);
int execute_command(char **path_values, char *command);
void free_args_array(char **args_array);

extern char **environ;

#endif
