#include "shell.h"
/**
 * main - launches shell from a script file or runs in interactive mode.
 * @argc: is the count of the arguments passed to the program
 * @argv: is an array of strings containing the arguments
 * Return: int
 **/
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
