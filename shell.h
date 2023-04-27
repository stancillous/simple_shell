#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 
#define MAX_ARGS 10 
#define MAX_ARGS_LENGTH 100 
#define MAX_ALIASES 100
#define MAX_ARG_LENGTH 256 
#define MAX_NUM_ARGS 10
#define MAX_PATH_LENGTH 100
char *_strtok(char *str, const char *delim);
void shellTwo(void);
void change_cd(char *args[]);
void handle_command_with_args(const char *command, char *args[]);
void print_environment(void);
int find_command_path(char *command, char *path);
/* void display_prompt();*/
/* void read_command(char *command);*/
/* void execute_command(char *command);*/
void execute_command_with_args(char *command, char *args[]);



/*handle command line separator (;)*/
void handle_command_line_separators(char *command);

/*handle $? and $$*/
void handle_variable_replacement(char *command);

/*set and unset env*/
void handle_setenv(char **args, int num_args);
void handle_unsetenv(char **args, int num_args);

/* Function to parse arguments from a command string*/
int parse_arguments(char *command, char **args);
/*handle exit command with argument*/

/*handle command line comments*/
void handle_command_line_comments(char *command);

/*handle exit command*/
void handle_exit(char **args, int num_args);
void shell(char *filename);


#endif /* SHELL_H */

