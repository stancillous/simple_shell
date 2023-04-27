#include "shell.h"

/**
 * parse_arguments - function to parse args
 * @command: command given
 * @args: array with the commands
 * Return: number of arguments
 */

int parse_arguments(char *command, char **args)
{
	int num_args = 0;
	char *token, *command_copy;

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
