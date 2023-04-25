#include "shell.h"
/*
 * main serves as the entry point to the program
 * The function takes two arguments, an integer argc
 * and a pointer to a pointer argv
 * which represent the number of command-line arguments
 * and an array of strings containing the argument
 * The function first checks whether the number of arguments
 * passed is equal to 2 using the argc variable.
 * If there are exactly 2 arguments,
 * it assumes that the second argument is the name of a file
 * containing commands to be executed
 * The function then calls the shell() function
 * passing the file name as an argument
 * If there are not exactly 2 arguments
 * the function assumes that the program is being run
 * in regular interactive mode and calls the shellTwo() function
 * The function returns 0 to indicate successful program execution
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		shell(argv[1]); /* Pass the file name as argument*/
	}
	else
	{
		shellTwo(); /* No file name provided, regular interactive mode*/
	}
	return (0);
}
