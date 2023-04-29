#include "shell.h"

/**
 * contains_dollar - checks for $
 * @args: args array
 * Return: int
 */

int contains_dollar(char *args[])
{
	int i;

	for (i = 1; args[i] != NULL; i++)
	{
		if (args[i][0] == '$' && args[i][1] != '$')
			return (1);
	}
	return (0);
}

/**
 * handle_dollar - handles $
 * @args: args array
 * Return: void
 */

void handle_dollar(char *args[])
{
	int i;
	char *var_name, *var_value;

	for (i = 1; args[i] != NULL; i++)
	{
		if (args[i][0] == '$' && args[i][1] != '$')
		{
			var_name = args[i] + 1;
			var_value = getenv(var_name);
			if (var_value == NULL)
				var_value = "";
			strcpy(args[i], var_value);
		}
	}
	handle_command_with_args(args[0], args);
}

/**
 * handle_comments - handles comments
 * @command: command passed
 * Return: void
 */

void handle_comments(char *command)
{
	int i, j;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '#')
		{
			if (i == 0 || (i > 0 && command[i - 1] == ' '))
			{
				command[i] = '\0';
				break;
			}
		}
	}
	for (j = i - 1; j >= 0 && command[j] == ' '; j--)
		command[j] = '\0';
}
