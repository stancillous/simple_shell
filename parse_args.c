#include "shell.h"
#include <ctype.h>
/**
 * parse_arguments - function to parse args
 * @command: command given
 * @args: array with the commands
 * Return: number of arguments
 */

int parse_arguments(char *command, char **args)
{
	int num_args = 0, i, j;
	char *token, *command_copy;

	int len = strlen(command);
	for (i = 0; isspace(command[i]); i++)
		;
	if (i == len)
		command[0] = '\0';
	for (j = len - 1; isspace(command[j]); j--)
		;
	command[j + 1] = '\0';
	memmove(command, command + i, j - 1 + 2);

	command_copy = strdup(command);
	token = _strtok(command_copy, " ");

	while (token != NULL && num_args < MAX_NUM_ARGS)
	{
		args[num_args++] = token;
		token = _strtok(NULL, " ");
	}
	args[num_args] = NULL;
	return (num_args);
}
