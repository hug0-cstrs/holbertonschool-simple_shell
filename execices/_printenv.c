#include <stdio.h>

extern char **environ;

int main (int ac, char **av, char **zizi)
{
	char **pipi = environ;
	int i = 0;

	while (zizi[i])
	{
		printf("%s\n", zizi[i]);
		i++;
	}
	i = 0;

	while (pipi[i])
	{
		printf("%s\n", pipi[i]);
		i++;
	}

	printf("%p\n%p\n", zizi, environ); 

	return (0);
}
