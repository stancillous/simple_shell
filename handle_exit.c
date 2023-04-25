#include "shell.h"
/**
 * This function handles the 'exit' command in a shell program
 * It takes an array of arguments and the number of arguments as input
 * If there is only one argument, it exits the shell with a success status
 * If there are two arguments
 * it converts the first argument to an integer using the atoi() function
 * and exits the shell with that status
 * If there are more than two arguments
 * it prints an error message to stdout indicating the correct usage
 */
void handle_exit(char **args, int num_args)
{
	if (num_args == 1)
	{
		exit(0);
	}
	else if (num_args == 2)
	{
		int exit_status = atoi(args[0]);

		exit(exit_status);
	}
	else
	{
		printf("Usage: exit status\n");
	}
}
