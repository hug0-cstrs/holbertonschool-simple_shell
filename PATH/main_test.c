#include "simple_shell.h"

int main(int argc, char *argv[], char *envp[])
{
	int getpath_status = get_path(envp);
	(void)argc;
	(void)argv;

	printf("%d\n", getpath_status);

	return (0);
}
