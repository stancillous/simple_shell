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
	int exit_status = 0;
	char *pos;
	char exit_status_str[12];
	int len;

	while ((pos = strstr(command, "$$")) != NULL)
	{
		char pid[100];

		sprintf(pid, "%ld", (long int)getpid());
		memcpy(pos, pid, strlen(pid));
	}
	/*Replace $? with actual exit status*/
	while ((pos = strstr(command, "$?")) != NULL)
	{
		exit_status = 0;
		snprintf(exit_status_str, 12, "%d", exit_status);
		len = strlen(exit_status_str);
		memmove(pos + len, pos + 2, strlen(pos) - 1);
		memcpy(pos, exit_status_str, len);
	}
}
