#include "shell.h"
#include <fcntl.h>
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
	int ret, fd;

	if (pid == 0)
	{/* Child process*/
		ret = execvp(command, args); /* Execute the command with arguments*/
		if (ret == -1)
		{
			fd = open("/dev/null", O_WRONLY);
			if (fd == -1)
			{
				perror("open /dev/null");
				exit(2);
			}
			if (dup2(fd, STDERR_FILENO) == -1)
			{
				perror("dup2");
				exit(2);
			}
			close(fd);
			perror("command not found");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		/* failed to fork*/
		perror("fork");
	}
}
