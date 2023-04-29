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

int contains_dollar(char *args[])
{
  int i;
    for (i = 1; args[i] != NULL; i++)
    {
        if (args[i][0] == '$' && args[i][1] != '$')
            return 1;
    }
    return 0;
}

void handle_dollar(char *args[])
{
  int i;

    for (i = 1; args[i] != NULL; i++)
    {
        if (args[i][0] == '$' && args[i][1] != '$')
        {
            char *var_name = args[i] + 1;
            char *var_value = getenv(var_name);
            if (var_value == NULL)
                var_value = "";
            strcpy(args[i], var_value);
        }
    }
    handle_command_with_args(args[0], args);
}


void handle_comments(char *command) {
    int i, j;

    for (i = 0; command[i] != '\0'; i++) {
        if (command[i] == '#') {
            if (i == 0 || (i > 0 && command[i-1] == ' ')) {
                command[i] = '\0';
                break;
            }
        }
    }

    for (j = i-1; j >= 0 && command[j] == ' '; j--) {
        command[j] = '\0';
    }
}

void check_commands(char *args[], int num_args)
{


	if (strcmp(args[0], "env") == 0)
	{
		if (!args[1])
			print_environment();
		else
			fprintf(stderr, "null");
	}


	else if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
	{
		if (num_args == 2)
			printf("%s\n", getenv("PATH"));
		else
			fprintf(stderr, "null");
	}
	else if (strcmp(args[0], "cd") == 0)
		change_cd(args);
	else if (strcmp(args[0], "setenv") == 0)
		handle_setenv(args, num_args);
	else if (strcmp(args[0], "unsetenv") == 0)
		handle_unsetenv(args, num_args);
	else if (strcmp(args[0], "exit") == 0)
		handle_exit(&args[1], num_args);
	else if (contains_dollar(args))
		handle_dollar(args);
	else
  {
		handle_command_with_args(args[0], args);
  }

}

/**
 * shell - main shell function
 * @filename: name of file
 * Return: void
 */
void shell(char *filename)
{
	FILE *fp;
	char line[1024];
	int i;

	pid_t pid;
	char *args[256];

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "./hsh: 0: Can't open %s\n", filename);
		exit(127);
	}
	while (fgets(line, sizeof(line), fp))
	{
		line[strcspn(line, "\n")] = 0;
		i = 0;
		args[i++] = strtok(line, " ");
		while (args[i - 1] != NULL && i < 256)
		{
			args[i++] = strtok(NULL, " ");
		}
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			perror("Error executing command");
			exit(1);
		}
		else if (pid < 0)
		{
			perror("Error forking process");
			exit(1);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
			if (WIFSIGNALED(status))
			{
				printf("Command terminated by signal %d\n", WTERMSIG(status));
			}
		}
	}
	fclose(fp);
}
/**
 * shellTwo - second shell function
 * Return: void
 */

void shellTwo(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_NUM_ARGS + 1];
	int num_args, i;
	FILE *input_stream = stdin;

	if (!isatty(fileno(stdin)))
		input_stream = stdin;
	while (fgets(command, MAX_COMMAND_LENGTH, input_stream))
	{
		if (feof(input_stream))
			break;
		command[strcspn(command, "\n")] = '\0';
		/*comment_pos = strchr(command, '#');
		if (comment_pos != NULL)
			*comment_pos = '\0';*/
		handle_comments(command);
		if (contains_separator(command))
		{
			handle_command_line_separators(command);
			continue;
		}
		handle_variable_replacement(command);

		for (i = 0; command[i] != '\0'; i++)
		{
			if (!isspace(command[i]))
				break;
		}
		if (command[i] == '\0')
			exit(EXIT_SUCCESS);
		num_args = parse_arguments(command, args);
		check_commands(args, num_args);
	}
}
