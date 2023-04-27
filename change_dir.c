#include "shell.h"
/**
 * change_cd - changes the current working directory of a shell program.
 * @args: An array of arguments, where the first element is the name of the
 * command ("cd") and the second element is the directory to change to
 * (or NULL or "-" for special cases)
 * Return (0)
 **/
void change_cd(char *args[])
{
	char *dir = args[1]; /* Get the directory argument*/
	char cwd[1024];

	if (dir == NULL)
	{/* If no argument is provided, change to the home directory*/
		dir = getenv("HOME");
	}
	else if (strcmp(dir, "-") == 0)
	{/* If argument is "-", change to the previous directory*/
		dir = getenv("OLDPWD");
	}
	if (chdir(dir) != 0)
	{/* If chdir fails, print error message to stderr*/
		fprintf(stderr, "cd: %s: No such file or directory\n", dir);
	}
	else
	{/* Update the PWD environment variable*/
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("PWD", cwd, 1);
		}
		else
		{
			fprintf(stderr, "cd: Failed to update PWD environment variable\n");
		}
	}
}
