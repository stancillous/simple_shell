#include "shell.h"
/**
 * handle_command_line_separators-This function executes
 * multiple shell commands separated by semicolons.
 * @command: refer to a series of shell commands separated by semicolons
 * Return 0
 **/
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
