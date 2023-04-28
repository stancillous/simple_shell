#include "shell.h"
/**
 * print_environment - prints all environment variables and their values
 * using environ, strtok(), and getenv()
 * Return: void
 **/
/**/
void print_environment(void)
{
	char **envp = __environ;

	while (*envp != NULL)
	{
		char *name = strchr(*envp, '=');

		if (name != NULL)
		{
			*name = '\0';
			name++;
			printf("%s=%s", *envp, name);
		}
		envp++;
	}
}
/*
 * void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
*/
