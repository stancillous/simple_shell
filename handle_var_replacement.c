#include "shell.h"
/**
 * This is a C function named handle_variable_replacement
 * that replaces two variables in a given string command.
 * The first variable to be replaced is $$
 * which represents the current process ID (PID) of the program
 * The second variable to be replaced is $?
 * which represents the exit status of the last command executed
 * The function uses getpid() to obtain the current PID
 * and stores it in a character array pid
 * Then, the sprintf() function is
 * used to convert the integer PID into a string and store it in pid
 * The memcpy() function is
 * used to replace the $$ variable
 * in the command string with the pid string
 * The function also assumes that the caller will pass
 * the value of the last command's exit status
 * in the last_exit_status integer variable.
 * The function converts this integer value to a string using sprintf()
 * and stores it in a character array exit_status
 * The memcpy() function is then used to replace the $? variable
 * in the command string with the exit_status string.
 * Overall, the function loops through the command string twice
 * replacing the $$ and $? variables with their respective values.
 */
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
