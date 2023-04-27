#include "shell.h"

/**
 * find_command_path - handle the path
 * @command: command passed
 * @path: path
 * Return: int
 */

int find_command_path(char *command, char *path)
{
	char *env_path = getenv("PATH");
	char *dir = _strtok(env_path, ":");

	if (env_path == NULL)
	{
		printf("Failed to get PATH env variable\n");
		return (0);
	}

	while (dir != NULL)
	{
		snprintf(path, MAX_PATH_LENGTH, "%s/%s", dir, command);
		if (access(path, X_OK) == 0)
		{
			return (1);
		}
		dir = _strtok(NULL, ":");
	}
	return (0);
}
