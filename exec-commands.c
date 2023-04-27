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
	pid_t pid = fork(); /* Fork a child process*/

	if (pid == 0)
	{/* Child process*/
		execvp(command, args); /* Execute the command with arguments*/
		perror("execvp"); /* Print error message if execvp fails*/
		exit(EXIT_FAILURE); /* Exit child process with failure status*/
	}
	else if (pid > 0)
	{/* Parent process*/
		int status;

		waitpid(pid, &status, 0); /* Wait for the child process to complete*/
		/*
		 * if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			printf("Child process exited with status: %d\n", exit_status);
		}
		else if (WIFSIGNALED(status))
		{
			int signal_number = WTERMSIG(status);
			printf("Child process terminated with signal: %d\n", signal_number);
		}
		*/
	}
	else
	{
		/* failed to fork*/
		perror("fork");
	}
}
