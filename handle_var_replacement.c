#include "shell.h"
/**
 * handle_variable_replacement-This function replaces instances of
 * "$$" and "$?" in the command string with process ID
 * and last exit status respectively.
 * @command: refers to the input command string that
 * may contain variables to be replaced.
 * Return 0
 **/
void handle_variable_replacement(char *command)
{
	int last_exit_status = 0;
	char *pos;

	while ((pos = strstr(command, "$$")) != NULL)
	{
		char pid[100];

		sprintf(pid, "%ld", (long int)getpid());
		memcpy(pos, pid, strlen(pid));
	}
	/*Replace $? with actual exit status*/
	while ((pos = strstr(command, "$?")) != NULL)
	{
		char exit_status[40];

		sprintf(exit_status, "%d", last_exit_status);
		memcpy(pos, exit_status, strlen(exit_status));
	}
}
