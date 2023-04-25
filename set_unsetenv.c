#include "shell.h"

/**
 * handle_setenv - sets a variable
 * @args: command array
 * @num_args: number of args
 * Return: void
 */

void handle_setenv(char **args, int num_args)
{
	int result;

	if (num_args != 3)
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	else
	{
		result = setenv(args[1], args[2], 1);
		if (result != 0)
			fprintf(stderr, "failed to set environment variable\n");
	}
}

/**
 * handle_unsetenv - unsets a variable
 * @args: commands array
 * @num_args: number of args
 * Return: void
 */

void handle_unsetenv(char **args, int num_args)
{
	int result;

	if (num_args != 2)
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	else
	{
		result = unsetenv(args[1]);
		if (result != 0)
			fprintf(stderr, "failed to unset variable\n");
	}
}
