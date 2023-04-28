#include "shell.h"
/**
 * handle_command_with_args - Forks a child process to execute a command
 * with arguments, waits for completion, and prints errors
 * @command: is a string that represents the command to be executed
 * @args: is an array of strings that represents
 * the arguments to be passed to the command
 * Return 0
 **/
void handle_command_with_args(const char *command, char *args[])
{
	pid_t pid = 0; /* Fork a child process*/

	if (pid == 0)
	{/* Child process*/
		execvp(command, args); /* Execute the command with arguments*/
		perror("execvp"); /* Print error message if execvp fails*/
		exit(EXIT_FAILURE); /* Exit child process with failure status*/
	}
	else
	{
		/* failed to fork*/
		perror("fork");
	}
}
