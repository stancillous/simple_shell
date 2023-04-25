#include "shell.h"

/**
 * display_promt - displays prompt
 * Return: void
 */

void display_prompt(void)
{
	printf("COOL_SHELL$ ");
	fflush(stdout);
}

/**
 * read_command - reads entered command
 * @command: command passed
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
 * contains_seprator - checks for ;
 * @comand: command passed
 * Return: void
 */

int contains_separator(const char *command)
{
	return (strchr(command, ';') != NULL);
}

/**
 * shell - main shell function
 * @filename: file passed from command line
 * Return: void
 */

id shell(char *filename)
{
    FILE *file;
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_NUM_ARGS + 1];
    int num_args;
    int read_from_file = 0;
char *comment_pos;
    if (filename != NULL)
    {
        file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Failed to open file: %s\n", filename);
            return;
        }
        read_from_file = 1;
    }

    while (1)
    {
        if (!read_from_file)
        {
            display_prompt();
            read_command(command);
        }
        else
        {
            if (fgets(command, MAX_COMMAND_LENGTH, file) == NULL)
            {
                break;
            }
            printf("%s", command);
        }

        comment_pos = strchr(command, '#');
        if (comment_pos != NULL)
        {
            *comment_pos = '\0';
        }

        if (contains_separator(command))
        {
            handle_command_line_separators(command);
            continue;
        }

        handle_variable_replacement(command);

        num_args = parse_arguments(command, args);

        if (strcmp(args[0], "env") == 0)
        {
            if (!args[1])
            {
                print_environment();
            }
            else
            {
                fprintf(stderr, "Incorrect usage of the command env\n");
            }
        }
        else if (strcmp(args[0], "cd") == 0)
        {
            change_cd(args);
        }
        else if (strcmp(args[0], "setenv") == 0)
        {
            handle_setenv(args, num_args);
            continue;
        }
        else if (strcmp(args[0], "unsetenv") == 0)
        {
            handle_unsetenv(args, num_args);
            continue;
        }
        else if (strcmp(args[0], "exit") == 0)
        {
            handle_exit(&args[1], num_args);
        }
        else if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
        {
            if (num_args == 2)
            {
                printf("%s\n", getenv("PATH"));
            }
            else
            {
                fprintf(stderr, "Incorrect usage of the command echo $PATH\n");
            }
        }
        else
        {
            handle_command_with_args(args[0], args);
        }
    }

    if (filename != NULL)
    {
        fclose(file);
    }
}


void shellTwo()
{
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_NUM_ARGS + 1];
    int num_args;
  char *comment_pos;
    while (1) {
        display_prompt();
        read_command(command);

      if(feof(stdin))
      {
          printf("\n");
          break;
      }

       comment_pos = strchr(command, '#');
        if (comment_pos != NULL) {
            *comment_pos = '\0';
        }


      if (contains_separator(command))
        {
            handle_command_line_separators(command);
            continue;
        }


      handle_variable_replacement(command);




      num_args = parse_arguments(command, args);

        if (strcmp(args[0], "env") == 0)
        {
          if (!args[1])
          {
            print_environment();
          }

          else
          {
            fprintf(stderr, "Incorrect usage of the command env\n");

          }
        }


      else if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
        {
            if (num_args == 2)
            {
                printf("%s\n", getenv("PATH"));
            }
            else
            {
                fprintf(stderr, "Incorrect usage of the command echo $PATH\n");
            }
        }
        else if (strcmp(args[0], "cd") == 0)
        {
          change_cd(args);
        }

        else if (strcmp(args[0], "setenv") == 0)
        {
          handle_setenv(args, num_args);
          continue;
        }
        else if (strcmp(args[0], "unsetenv") == 0)
        {
          handle_unsetenv(args, num_args);
          continue;
        }

        else if (strcmp(args[0], "exit") == 0)
        {
            handle_exit(&args[1], num_args);
        }
        else
        {
            handle_command_with_args(args[0], args);
        }

    }


}
