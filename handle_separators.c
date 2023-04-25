#include "shell.h"
/**
 * handle_command_line_separator handles command line separators
 * It takes a command string as input
 * It splits the command into multiple commands using the separator ";"
 * as delimiter using the strtok() function
 * For each command, it forks a new child process using the fork() function
 * If the process is the child process
 * it parses the command and its arguments using the strtok() function
 * and then executes the command with the execvp() function
 * If execvp() fails, it prints an error message to stderr
 * using the perror() function
 * and exits the child process with a failure status
 * If the process is the parent process
 * it waits for the child process to finish using the waitpid() function
 * If the fork() function fails, it prints an error message to stderr
 * using the perror() function
 * and exits the child process with a failure status
 */
void handle_command_line_separators(char *command)
{
	const char *separator = ";";
	char *token;
	/*Split the command using the separator as delimiter*/
	token = strtok(command, separator);
	while (token != NULL)
	{/* Fork a new process to execute the command*/
		pid_t pid = fork();

		if (pid == 0)
		{/* Child process*/
			/* Parse arguments for the command*/
			char *args[64];
			int num_args = 0;

			args[num_args++] = strtok(token, " ");
			while
				((args[num_args++] = strtok(NULL, " ")) != NULL);
			execvp(args[0], args);
			/* execvp() will only return if there is an error*/
			perror("execvp");
			exit(1);
		}
		else if (pid > 0)
		{
			/* Parent process*/
			/* Wait for the child process to finish*/
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			/* Forking failed*/
			perror("fork");
			exit(1);
		}
		/*Get the next token*/
		token = strtok(NULL, separator);
	}
}
