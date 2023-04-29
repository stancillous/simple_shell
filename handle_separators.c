#include "shell.h"
#include <ctype.h>

/**
 * trim - trims
 * @str: string passed
 * Return: void
 */

char *trim(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}
/**
 * handle_command_line_separators - handles command line separators
 * @command: command passed
 * Return: void
 */

void handle_command_line_separators(char *command)
{
	const char *separator = ";";
	char *token, *trimmed_command;
	pid_t pid;
	int num_args = 0;
	char *args[64];

	token = strtok(command, separator);
	while (token != NULL)
	{
		trimmed_command = trim(token);
		pid = fork();
		if (pid == 0)
		{
			args[num_args++] = strtok(trimmed_command, " ");
			while ((args[num_args++] = strtok(NULL, " ")) != NULL)
				;
			execvp(args[0], args);
			perror("execvp");
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("fork");
			exit(1);
		}
		token = strtok(NULL, separator);
	}
}
