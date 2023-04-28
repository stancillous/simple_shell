#include "shell.h"

int count_command(char **args, int num_args)
{

    int count = 0, i;
    for (i = 0; i < num_args; i++) {
        if (strcmp(args[i], "/bin/ls") == 0) {
            count++;
        }
    }
    return count;
}

void execute_command_multiple_times(int count)
{
  int i, status;
  for (i = 0; i < count; i++) {

    status = system("/bin/ls");
    if (status != 0) {
        fprintf(stderr, "Error executing command: /bin/ls\n");
    }
  }
}
