#include "shell.h"

/**
 * print_environment - prints the environment
 * Return: void
 */

extern char **environ;

void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
