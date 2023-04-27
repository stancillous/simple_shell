#include "shell.h"

/**
 * contains_separator - check for ;
 * @command: command passed
 * Return: int
 */

int contains_separator(const char *command)
{
	return (strchr(command, ';') != NULL);
}
