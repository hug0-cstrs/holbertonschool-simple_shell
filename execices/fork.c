#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid = 0;
    pid_t pid = 0;

    printf("Before fork\n");
    printf("My pid is %u\n", getpid());
    printf("Child pid is %u\n", pid);
    printf("\n \n");

    my_pid = getpid();

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }

    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    printf("Child pid is %u\n", pid);

    return (0);
}
