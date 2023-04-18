#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	int status;
	char **argv = NULL;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("Son pid %d from parent pid %d \n", getpid(), getppid());
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}

			return (0);
		}
		wait(&status);
	}
	return (0);
}
