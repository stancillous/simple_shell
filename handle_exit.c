#include "shell.h"
/**
 * handle_exit - This function handles the "exit" command in a shell program
 * allowing the user to exit with an optional exit status
 * @args: Pointer to array of strings with command arguments.
 * @num_args: Number of arguments, including command
 **/
void handle_exit(char **args, int num_args)
{
	if (num_args == 1)
	{
		exit(0);
	}
	else if (num_args == 2)
	{
		int exit_status = atoi(args[0]);
		if (exit_status < 0)
		{
			fprintf(stderr, "./hsh: 1:exit: Illegal number: %d\n", atoi(args[0]));
			exit(0);
		}

		exit(exit_status);
	}
	else
	{
		printf("Usage: exit status\n");
	}
}
