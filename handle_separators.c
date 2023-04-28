#include "shell.h"
#include <ctype.h>

/**
* trims - trims
*str: string passed
Return: void
*/

char *trim(char *str)
{
    char *end;

    /* Trim leading space */
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        /* All spaces */
        return str;
    }

    /* Trim trailing space */
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    /* Write new null terminator */
    *(end + 1) = '\0';

    return str;
}

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
    {
        /* Remove any leading/trailing spaces */
        char *trimmed_command = trim(token);

        /* Fork a new process to execute the command */
        pid_t pid = fork();

        if (pid == 0)
        {
            /* Child process */
            /* Parse arguments for the command */
            char *args[64];
            int num_args = 0;

            args[num_args++] = strtok(trimmed_command, " ");
            while ((args[num_args++] = strtok(NULL, " ")) != NULL);

            execvp(args[0], args);
            /* execvp() will only return if there is an error */
            perror("execvp");
            exit(1);
        }
        else if (pid > 0)
        {
            /* Parent process */
            /* Wait for the child process to finish */
            int status;
            waitpid(pid, &status, 0);
        }
        else
        {
            /* Forking failed */
            perror("fork");
            exit(1);
        }

        /*Get the next token*/
        token = strtok(NULL, separator);
    }
}

