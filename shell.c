#include "shell.h"

/**
 * display_prompt - displays prompt
 * Return: void
 */
void display_prompt(void)
{
	printf(" ");
	fflush(stdout);
}

/**
 * read_command - reads comand entered
 * @command: command
 * Return: void
 */
void read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin))
	{
	}
	command[strcspn(command, "\n")] = '\0';
}

/**
 * check_commands - check command
 * @args: array of commands
 * @num_args: number of args
 * Return: void
 */
void check_commands(char *args[], int num_args)
{
	if (strcmp(args[0], "env") == 0)
	{
		if (!args[1])
			print_environment();
		else
			fprintf(stderr, "Incorrect usage of the command env");
	}
	else if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
	{
		if (num_args == 2)
			printf("%s\n", getenv("PATH"));
		else
			fprintf(stderr, "Incorrect usage of the command echo $PATH\n");
	}
	else if (strcmp(args[0], "cd") == 0)
		change_cd(args);
	else if (strcmp(args[0], "setenv") == 0)
		handle_setenv(args, num_args);
	else if (strcmp(args[0], "unsetenv") == 0)
		handle_unsetenv(args, num_args);
	else if (strcmp(args[0], "exit") == 0)
		handle_exit(&args[1], num_args);
	else
		handle_command_with_args(args[0], args);
}

/**
 * shell - main shell function
 * @filename: name of file
 * Return: void
 */
void shell(char *filename)
{
	FILE *file = NULL;
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_NUM_ARGS + 1], *comment_pos = NULL, *hash;
	int num_args, read_from_file = 0;

	if (filename != NULL)
	{
		file = fopen(filename, "r");
		if (file == NULL)
		{
			fprintf(stderr, "./hsh: 0: Can't open %s\n", filename);
			return;
		}
		read_from_file = 1;
	}
	while (1)
	{
		if (!read_from_file)
			display_prompt(), read_command(command);
		else
		{
			if (fgets(command, MAX_COMMAND_LENGTH, file) == NULL)
				break;
			printf("%s", command);
		}
		if (feof(file))
			break;
		hash = comment_pos = strchr(command, '#');
		if (hash != NULL)
			*comment_pos = '\0';
		if (contains_separator(command))
		{
			handle_command_line_separators(command);
			continue;
		}
		handle_variable_replacement(command);
		num_args = parse_arguments(command, args);
		check_commands(args, num_args);
	}
	if (filename != NULL)
		fclose(file);
}
/**
 * shellTwo - second shell function
 * Return: void
 */

void shellTwo(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_NUM_ARGS + 1], *comment_pos = NULL;
	int num_args;
	FILE *input_stream = stdin;

	if (!isatty(fileno(stdin)))
		input_stream = stdin;
	while (fgets(command, MAX_COMMAND_LENGTH, input_stream))
	{
		if (feof(input_stream))
			break;
		command[strcspn(command, "\n")] = '\0';
		comment_pos = strchr(command, '#');
		if (comment_pos != NULL)
			*comment_pos = '\0';
		if (contains_separator(command))
		{
			handle_command_line_separators(command);
			continue;
		}
		handle_variable_replacement(command);
		num_args = parse_arguments(command, args);
		check_commands(args, num_args);
	}
}
