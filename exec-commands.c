#include "shell.h"
/**
 * handle_command_with_args handles a shell command with arguments
 * It takes a command string and an array of arguments as input
 * It forks a child process using the fork() function
 * If the process is the child process
 * it executes the command with arguments using the execvp() function
 * If execvp() fails
 * it prints an error message to stderr using the perror() function
 * and exits the child process with a failure status
 * If the process is the parent process
 * it waits for the child process to complete using the waitpid() function
 * If the child process exits normally
 * it gets the exit status using the WEXITSTATUS() macro
 * and prints it to stdout
 * If the child process is terminated by a signal
 * it gets the signal number using the WTERMSIG() macro
 * and prints it to stdout
 * If the fork() function fails
 * it prints an error message to stderr using the perror() function
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
		/*if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			printf("Child process exited with status: %d\n", exit_status);
		}
		else if (WIFSIGNALED(status))
		{
			int signal_number = WTERMSIG(status);
			printf("Child process terminated with signal: %d\n", signal_number);
		}*/
	}
	else
	{
		/* failed to fork*/
		perror("fork");
	}
}
