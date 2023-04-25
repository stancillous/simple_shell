#include "shell.h"
/**
 * change_cd changes the current working directory of a shell program.
 * It takes an array of arguments as input
 * The first element of the array is the directory to be changed to.
 * If the directory argument is NULL
 * It changes the directory to the user's home directory.
 * If the directory argument is "-"
 * It changes the directory to the previously visited directory
 * The function attempts to change the directory using the chdir() function.
 * If chdir() fails
 * It prints an error message to stderr using the fprintf() function.
 * If chdir() succeeds
 * It updates the value of the PWD environment variable
 * to the new current working directory using the setenv() function
 * If updating the PWD environment variable fails
 * It prints an error message to stderr using the fprintf() function.
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
