#include "shell.h"
/**
 * execute_command - executes a shell command and
 * prints its output to the console
 * @command: string argument specifying the shell command to execute
 * Return: int
 */
void execute_command(const char *command)
{
	char buffer[1024];
	FILE *pipe = popen(command, "r");

	if (!pipe)
	{
		printf("Failed to open pipe for command %s\n", command);
		return;
	}
	while (fgets(buffer, sizeof(buffer), pipe))
	{
		printf("%s", buffer);
	}
	pclose(pipe);
}
